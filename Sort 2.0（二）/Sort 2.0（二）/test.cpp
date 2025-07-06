#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"

//测试快排
void test01()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int begin = clock();
	QuickSort(arr, 0, 9);
	int end = clock();
	printf("%d\n", end - begin);
	Print(arr, 10);
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
	
	int begin1 = clock();
	QuickSort(a1, 0, N - 1);
	int end1 = clock();
	printf("快排 ：%d\n", end1 - begin1);

	int begin2 = clock();
	QuickSort(a2, 0, N - 1);
	int end2 = clock();
	printf("快排：%d\n", end2 - begin2);

	int begin3 = clock();
	QuickSort(a3, 0, N - 1);
	int end3 = clock();
	printf("快排：%d\n", end3 - begin3);

	free(a1);
	free(a2);
	free(a3);

}

int main()
{
	//test01();
	Test();
	return 0;
}