#pragma once
#include<stdio.h>
#include<string.h>
//定义宏，在修改表长时更加方便。
#define N 10

//使用typedef为类型起别名，存储其他类型的数据时也方便修改
//例如存储double类型的数据时直接将int修改成double
typedef int SQDataType;

typedef struct SeqList
{
	SQDataType arr[N];
	int size;//实际存储数据的个数
}SL;//将struct SeqList简写为SL

//初始化函数声明
void SeqListInit(SL* psl);

//尾插函数声明
void SeqListPushBack(SL* psl, SQDataType x);

//头插函数声明
void SeqListPushFront(SL* psl, SQDataType x);

//尾删函数声明

//头删函数声明