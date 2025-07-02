#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"

//≤‚ ‘øÏ≈≈
void test01()
{
	int arr[10] = { 2,1,5,3,6,7,9,4,0,8 };
	QuickSort(arr, 0, 9);
	Print(arr, 10);
}

int main()
{
	test01();
	return 0;
}