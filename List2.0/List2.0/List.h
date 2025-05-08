#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;//存放的数据元素
	struct ListNode* prev;//前驱指针
	struct ListNode* next;//后继指针
}ListNode;
//C++中双向链表叫List，所以起名也叫List

//申请新结点
ListNode* BuyListNode(LTDataType x);

//打印函数（方便调试观看）
void PrintList(ListNode* phead);

//初始化函数
ListNode* ListInit();
//或者：void ListInit(ListNode** pphead);

//销毁函数（通过头结点可以链表第一个有效节点进行修改，因此不需要传二级指针）
void ListDestory(ListNode* phead);

//尾插函数
void ListPushBack(ListNode* phead, LTDataType x);

//头插函数
void ListPushFront(ListNode* phead, LTDataType x);
 
//头删函数
void ListPopFront(ListNode* phead);

//尾删函数
void ListPopBack(ListNode* phead);

//查找函数
ListNode* ListFind(ListNode* phead, LTDataType x);

//在pos位置前插入结点
void ListInsert(ListNode* pos, LTDataType x);

//删除pos位置的结点
void ListErase(ListNode* pos);

//判空函数
bool ListEmpty(ListNode* phead);