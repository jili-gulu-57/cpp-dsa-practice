#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;

//结点的结构体
typedef struct SListNode
{
	SLDataType data;//数据域
	struct SListNode* next;//指向下一个结点的指针域，所以指针类型应该为struct SListNode*
}SLTNode;//起别名，将struct SListNode简写成SLTNode

//打印函数（方便调试）
void SListPrint(SLTNode* phead);

//申请新结点
SLTNode* BuySListNode(SLDataType x);

//尾插函数
void SListPushBack(SLTNode** pphead, SLDataType x);//需要传二级指针，否则形参的改变不影响实参

//头插函数
void SListPushFront(SLTNode** pphead, SLDataType x);

//尾删函数
void SListPopBack(SLTNode** pphead);

//头删函数
void SListPopFront(SLTNode** pphead);

//在指定位置之前插入函数
void SListInsert(SLTNode** pphead, SLTNode* pos, SLDataType x);

//在指定位置之后插入函数
void SListInsertAfter(SLTNode** pphead, SLTNode* pos, SLDataType x);

//删除指定结点
void SListErase(SLTNode** pphead, SLTNode* pos);

//查找
SLTNode* SListFind(SLTNode* phead, SLDataType x);

//销毁链表函数
void SListDestory(SLTNode** pphead);