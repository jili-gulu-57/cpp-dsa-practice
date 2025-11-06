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
//void QuickSort(int* arr, int left, int right)
//{
//	if (left >= right)
//		return;
//
//	int begin = left, end = right;
//	//每次选取左边的值为基值，但在数组有序的情况下，时间复杂度最坏，为O(N^2);
//	//int pivot = begin;
//	
//	//采用三数取中，避免上述情况
//	int index = GetMidIndex(arr, left, right);
//	int pivot = index;
//	Swap(&arr[begin], &arr[index]);
//	int key = arr[begin];
//
//	while (begin < end)
//	{
//		while (begin < end && arr[end] >= key)
//			end--;
//		Swap(&arr[pivot], &arr[end]);
//		//arr[pivot] = arr[end];
//		pivot = end;
//		while (begin < end && arr[begin] <= key)
//			begin++;
//		Swap(&arr[pivot], &arr[begin]);
//		//arr[pivot] = arr[begin];
//		pivot = begin;
//		
//	}
//
//	pivot = begin;
//	arr[pivot] = key;
//
//	//小区间优化
//	if ((pivot - 1 - left) > 10)
//		QuickSort(arr, left, pivot - 1);
//	else
//		InsertSort(arr + left, pivot - left);
//	if ((right - pivot - 1) > 10)
//		QuickSort(arr, pivot + 1, right);
//	else
//		InsertSort(arr + pivot + 1, right - pivot);
//}


//快排（自己写）
void QuickSort(int* arr, int begin,int end)
{
	//递归出口
	if (begin >= end)
		return;

	int left = begin, right = end;
	int pivot = arr[left];	//选择第一个数据为基准值，0下标的位置即为坑
	while (left < right)
	{
		//内部循环可能会出现left==right的情况，所以内部也需要判断
		while (left < right&&arr[right] >= pivot)
		{
			right--;
		}
		//走到这里说明此时arr[right]的数据小于pivot，填坑
		arr[left] = arr[right];
		left++;	

		while (left < right&&arr[left] <= pivot)
		{
			left++;
		}
		//走到这里说明此时arr[left]的数据大于pivot，填坑
		arr[right] = arr[left];
		right--;
	}
	//left等于right时，此时的位置就是pivot的位置
	//left等于right时，此时的位置就是pivot的位置
	arr[left] = pivot;

	//左区间为[begin,left-1]
	QuickSort(arr, begin, left - 1);	//递归左区间

	//[right+1,end]
	QuickSort(arr, right + 1, end);		//递归右区间
	
}

//void QuickSort(int* arr, int begin, int end)
//{
//	if (begin >= end) return;
//
//	int left = begin, right = end;
//	int pivot = arr[left];
//
//	while (left < right)
//	{
//		while (left < right && arr[right] >= pivot)
//			right--;
//		arr[left] = arr[right];
//		left++;  // 你坚持保留这句
//
//		while (left < right && arr[left] <= pivot) left++;
//		arr[right] = arr[left];
//		right--;  // 你坚持保留这句
//	}
//
//	arr[left] = pivot;
//
//	//  打印 pivot 和左右区间
//	printf("pivot=%d, final pos=%d, left=[", pivot, left);
//	for (int i = begin; i < left; ++i) printf("%d ", arr[i]);
//	printf("], right=[");
//	for (int i = left + 1; i <= end; ++i) printf("%d ", arr[i]);
//	printf("]\n");
//
//	QuickSort(arr, begin, left - 1);
//	QuickSort(arr, left + 1, end);
//}

//归并排序（凡是递归，参数都得是左右区间）
void _MergeSort(int* arr, int left, int right, int* tmp)
{
	if (left == right)
		return;

	int mid = (left + right) >> 1;
	//[left,mid] [mid+1,right]
	_MergeSort(arr, left, mid, tmp);
	_MergeSort(arr, mid+1, right, tmp);

	//归并
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
			tmp[index++] = arr[begin1++];
		else
			tmp[index++] = arr[begin2++];
	}
	while (begin1 <= end1)
		tmp[index++] = arr[begin1++];
	while (begin2 <= end2)
		tmp[index++] = arr[begin2++];

	//拷贝
	for (int i = left; i <= right; i++)
		arr[i] = tmp[i];
}

void MergeSort(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(arr, 0, n - 1,tmp);
	free(tmp);
}
