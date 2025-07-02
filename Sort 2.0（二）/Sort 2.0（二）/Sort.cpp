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

//快排（挖坑法）
void QuickSort(int* arr, int left, int right)
{
	if (left >= right)
		return;

	int begin = left, end = right;
	int pivot = begin;
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

	QuickSort(arr, left, pivot - 1);
	QuickSort(arr, pivot + 1, right);
}