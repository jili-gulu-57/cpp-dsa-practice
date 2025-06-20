#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include"Heap.h"

//默认都是升序

//打印函数
void Print(int* arr, int size);

//交换函数
void Swap(int* x, int* y);

//冒泡排序
void BubbleSort(int* arr, int size);

//直接插入排序
void InsertSort(int* arr, int size);

//希尔排序
void ShellSort(int* arr, int size);

//堆排序
void HeapSort(int* arr, int size);
