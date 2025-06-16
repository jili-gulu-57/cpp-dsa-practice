#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int HPDataType;
//定义堆的结构--数组
typedef struct Heap
{
	HPDataType* arr;
	int size;     //有效数据个数
	int capacity; //数组空间大小
}HP;

//初始化
void HPInit(HP* php);

//销毁
void HPDestory(HP* php);

//插入数据
void HPPush(HP* php, HPDataType x);

//向上调整算法
void AdjustUp(HPDataType* arr,int child);

//交换函数
void Swap(int* x, int* y);

//打印函数
void HPPrint(HP* php);

//删除数据
void HPPop(HP* php);

//向下调整算法
void AdjustDown(HPDataType* arr, int parent, int size);

//取堆顶数据
HPDataType HPTop(HP* php);

//判断堆是否为空
bool HPEmpty(HP* php);