#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
#include<iostream>
using namespace std;

//≤‚ ‘√∞≈›≈≈–Ú
void test01()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	BubbleSort(arr, sizeof(arr) / sizeof(int));
	Print(arr, sizeof(arr) / sizeof(int));
}

//≤‚ ‘≤Â»Î≈≈–Ú
void test02()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	InsertSort(arr, sizeof(arr) / sizeof(int));
	Print(arr, sizeof(arr) / sizeof(int));
}

//≤‚ ‘œ£∂˚≈≈–Ú
void test03()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	ShellSort(arr, sizeof(arr) / sizeof(int));
	Print(arr, sizeof(arr) / sizeof(int));
}

//≤‚ ‘∂—≈≈–Ú
void test04()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	HeapSort(arr, sizeof(arr) / sizeof(int));
	Print(arr, sizeof(arr) / sizeof(int));
}

//≤‚ ‘÷±Ω”—°‘Ò≈≈–Ú
void test05()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0,-1 };
	SelectSort(arr, sizeof(arr) / sizeof(int));
	Print(arr, sizeof(arr) / sizeof(int));
}

//∂‘±»∏˜÷÷≈≈–Ú
void testsort()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}

	int begin1 = clock();
	BubbleSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	InsertSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	ShellSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	SelectSort(a5, N);
	int end5 = clock();

	printf("√∞≈›≈≈–Ú£∫%d\n", end1 - begin1);
	printf("≤Â»Î≈≈–Ú£∫%d\n", end2 - begin2);
	printf("œ£∂˚≈≈–Ú£∫%d\n", end3 - begin3);
	printf("∂—≈≈–Ú£∫%d\n", end4 - begin4);
	printf("÷±Ω”—°‘Ò≈≈–Ú£∫%d\n", end5 - begin5);

}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//testsort();
	cout << "hello"<<31;
	return 0;
}
