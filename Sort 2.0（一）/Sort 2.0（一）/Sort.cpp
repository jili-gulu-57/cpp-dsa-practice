#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"

//打印函数
void Print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//交换函数
//void Swap(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}

//冒泡排序
void BubbleSort(int* arr, int size)
{
	int flag = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size - 1; j++)
		{
			if (arr[j] < arr[i])
			{
				flag = 1; 
				Swap(&arr[j], &arr[i]);
			}
		}
		if (flag == 0)
			break;
	}
}

//直接插入排序
//时间复杂度O(n^2)
void InsertSort(int* arr,int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		//[0,end]区间为有序区间，依次将无序区间的元素插入到有序区间
		int end = i;//有序区间右端下标

		int tmp = arr[end + 1];//无序区间第一个元素

		while (end >= 0)
		{
			if (tmp < arr[end])
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = tmp;
	}

}

//希尔排序（直接插入排序优化版）
//时间复杂度取决于gap，范围是O(N*logN)~O(n^1.5)
//时间复杂度O(N^1.3)
//第一步：预排序 第二步：直接插入排序
void ShellSort(int* arr, int size)
{
	int gap = size;		//size为数组大小
	while (gap > 1)
	{
		gap = gap / 3 + 1;	//确保最后一次gap值为1

		for (int i = 0; i < size - gap; i++)
		{
			int end = i;
			int tmp = arr[end + gap];

			//子序列内排序
			while (end >= 0)
			{
				if (tmp < arr[end])
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
					break;
			}
			arr[end + gap] = tmp;
		}
	}
}


//堆排序
//满足除根结点外，左、右子树都是小/大堆，才能使用向下调整算法
void HeapSort(int* arr, int size)
{
	//先建堆
	//建堆有两种方法：
	//①：逐个插入数据，每个新数据插入时，使用向上调整算法建堆
	//②：所有数据插入完后，从最后一个非叶子结点开始向下调整建堆

	//方法①建堆，时间复杂度为O(nlogn)
	//for (int i = 0; i < size; i++)
	//{
	//	AdjustUp(arr, i);
	//}

	//方法②建堆，时间复杂度为O(n)
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(arr, i, size);
	}
	
	//排序
	//升序建大堆，降序建小堆
	int end = size - 1;
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, 0, end--);
	}
}

//直接选择排序（优化版）
void SelectSort(int* arr, int size)
{
	//每次选择两个数：最大值和最小值，最大值放到数组后面，最小值放到数组前面
	int begin = 0, end = size - 1;
	while (begin < end)
	{
		int min = begin, max = begin;
		//遍历未排序的数组，找到最大值和最小值
		for (int i = begin; i <= end; i++)
		{
			if (arr[i] > arr[max])
				max = i;
			if (arr[i] < arr[min])
				min = i;
		}
		if (max == begin)
			max = min;
		Swap(&arr[begin], &arr[min]);
		Swap(&arr[end], &arr[max]);
		begin++;
		end--;
	}
}
