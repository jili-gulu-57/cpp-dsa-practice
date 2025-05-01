#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

//使用typedef为类型起别名，存储其他类型的数据时也方便修改
//例如存储double类型的数据时直接将int修改成double
typedef int SQDataType;

typedef struct SeqList
{
	SQDataType* arr;
	int size;    //记录当前实际存储数据的个数
	int capacity;//顺序表容量大小
}SL;//将struct SeqList简写为SL

//初始化函数声明
void SLInit(SL* ps);

//销毁函数声明
void SLDestory(SL* ps);

//打印顺序表（方便调试）
void SLPrint(SL* ps);

//检查空间是否充足
void SLCheckCapacity(SL* ps);

//尾插函数声明
void SLPushBack(SL* ps, SQDataType x);

//头插函数声明
void SLPushFront(SL* ps, SQDataType x);

//指定位置插入函数声明
void SLInsert(SL* ps, SQDataType x, int pos);

//尾删函数声明
void SLPopBack(SL* ps);

//头删函数声明
void SLPopFront(SL* ps);

//删除指定位置的数据
void SLErase(SL* ps, int pos);

//查找指定数据
int SLFind(SL* ps, SQDataType x);