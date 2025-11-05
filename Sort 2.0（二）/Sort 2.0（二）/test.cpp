#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"



//测试直接插入排序
void test02()
{
	int arr[] = { 6,7,2,0,4,9,5,8,1,3 ,8,28,19,38};
	printf("排序前：");
	Print(arr, sizeof(arr) / sizeof(int));
	InsertSort(arr, sizeof(arr) / sizeof(int));
	printf("排序后：");
	Print(arr, sizeof(arr) / sizeof(int));
}

//测试归并排序
void test03()
{
	int arr[] = { 6,7,2,0,4,9,5,8,1,3 ,8,28,19,38 };
	printf("排序前：");
	Print(arr, sizeof(arr) / sizeof(int));
	MergeSort(arr, sizeof(arr) / sizeof(int));
	printf("排序后：");
	Print(arr, sizeof(arr) / sizeof(int));
}

//各种排序对比
void Test()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3= (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
	}
	
	//Print(a1, N);
	printf("\n");
	QuickSort(a1, 0, N - 1);
	Print(a1, N);

	////Print(a2, N);
	////QuickSort(a2, 0, N - 1);
	////Print(a2, N);
	////printf("\n");

	////Print(a3, N);
	////QuickSort(a3, 0, N - 1);
	////Print(a3, N);
	////printf("\n");

	//int begin1 = clock();
	//QuickSort(a1, 0, N - 1);
	//int end1 = clock();
	//printf("快排：%d\n", end1 - begin1);

	//int begin2 = clock();
	//QuickSort(a2, 0, N - 1);
	//int end2 = clock();
	//printf("快排：%d\n", end2 - begin2);

	//int begin3 = clock();
	//QuickSort(a3, 0, N - 1);
	//int end3 = clock();
	//printf("快排：%d\n", end3 - begin3);

	free(a1);
	free(a2);
	free(a3);

}

//void test01()
//{
//	int arr[10] = { 6,3,1,7,9,2,4,0,5,8 };
//	QuickSort(arr,0,9);
//	Print(arr, 10);
//}

//测试快排
void test01()
{
	//int arr[1000000] = { 0 };
	////数组有序，递归深度过大
	//for (int i = 0; i < 1000000; ++i)
	//{
	//	arr[i] = i;
	//}
	//QuickSort(arr, 0, 999999);

	// 构造一个【专门杀】的用例
	int killer[7] = { 5, 2, 3, 1, 4, 0, 6 };
	QuickSort(killer, 0, 6);
	for (int i = 0; i < 7; ++i) printf("%d ", killer[i]);

	//int arr[] = { 5,1,4,2,3};
	//int begin = clock();
	//QuickSort(arr, 0, sizeof(arr)/sizeof(int) - 1);
	//int end = clock();
	//printf("%d\n", end - begin);
	//Print(arr, sizeof(arr) / sizeof(int));

}

int main()
{

	//test01();
	//test02();
	//test03();
	Test();

	return 0;
}