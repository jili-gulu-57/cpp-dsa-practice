#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//交换函数
void Swap(int* x, int* y);

//打印函数
void Print(int* arr, int size);

//直接插入排序
void InsertSort(int* arr, int size);

//快排（挖坑法）
void QuickSort(int* arr, int left, int right);
