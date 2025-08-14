#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"

//交换函数
void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

//打印函数
void Print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

//三数取中法
int GetMidIndex(int* arr, int left, int right)
{
	int mid = (left + right) >> 1;//右移相当于除2

	if (arr[left] < arr[mid])
	{
		if (arr[right] > arr[mid])
			return mid;
		else if (arr[left] > arr[right])
			return left;
		else
			return right;
	}
	else //arr[left]>arr[right]
	{
		if (arr[mid] < arr[left])
			return mid;
		else if (arr[mid] < arr[right])
			return right;
		else
			return left;
	}
}

//直接插入排序
//时间复杂度O(n^2)
//void InsertSort(int* arr, int size)
//{
//	for (int i = 0; i < size - 1; i++)
//	{
//		//[0,end]区间为有序区间，依次将无序区间的元素插入到有序区间
//		int end = i;//有序区间右端下标
//
//		int tmp = arr[end + 1];//无序区间第一个元素
//
//		while (end >= 0)
//		{
//			if (tmp < arr[end])
//			{
//				arr[end + 1] = arr[end];
//				end--;
//			}
//			else
//			{
//				break;
//			}
//		}
//		arr[end + 1] = tmp;
//	}
//}

//直接插入排序（自己写）
void InsertSort(int* arr, int size)
{
	for (int i = 0; i < size-1; i++)
	{
		int end = i;	//标记有序区间的最后一个元素下标
		int begin = end + 1;	//无序区间第一个数下标
		int num = arr[end + 1];		//无序区间第一个数
		while (end >= 0)
		{
			if (num < arr[end])
			{
				Swap(&arr[begin], &arr[end]);
				end--;
				begin--;
			}
			else
				break;
		}
	}
}

//快排（挖坑法）
//时间复杂度为 O(N*logN)
void QuickSort(int* arr, int left, int right)
{
	if (left >= right)
		return;

	int begin = left, end = right;
	//每次选取左边的值为基值，但在数组有序的情况下，时间复杂度最坏，为O(N^2);
	//int pivot = begin;
	
	//采用三数取中，避免上述情况
	int index = GetMidIndex(arr, left, right);
	int pivot = index;
	Swap(&arr[begin], &arr[index]);
	int key = arr[begin];

	while (begin < end)
	{
		while (begin < end && arr[end] >= key)
			end--;
		Swap(&arr[pivot], &arr[end]);
		//arr[pivot] = arr[end];
		pivot = end;
		while (begin < end && arr[begin] <= key)
			begin++;
		Swap(&arr[pivot], &arr[begin]);
		//arr[pivot] = arr[begin];
		pivot = begin;
		
	}

	pivot = begin;
	arr[pivot] = key;

	//小区间优化
	if ((pivot - 1 - left) > 10)
		QuickSort(arr, left, pivot - 1);
	else
		InsertSort(arr + left, pivot - left);
	if ((right - pivot - 1) > 10)
		QuickSort(arr, pivot + 1, right);
	else
		InsertSort(arr + pivot + 1, right - pivot);
}

//归并排序
void _MergeSort(int* arr, int left, int right)
{
	if (left == right)
		return;
}

void MergeSort(int* arr, int n)
{
	
}
