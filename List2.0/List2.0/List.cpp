#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

//申请新结点
ListNode* BuyListNode(LTDataType x)
{
	ListNode* NewNode = (ListNode*)malloc(sizeof(ListNode));
	NewNode->data = x;
	NewNode->prev = NULL;
	NewNode->next = NULL;
	return NewNode;
}

//打印函数（方便调试观看）
void PrintList(ListNode* phead)
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//初始化函数
ListNode* ListInit()
{
	//初始链表为空时，需将头结点的prev指针和next指针都指向自己
	ListNode* phead = BuyListNode(-1);
	phead->next = phead->prev = phead;
	return phead;
}
//或：
/*void ListInit(ListNode** pphead)
{
	//初始链表为空时，需将头结点的prev指针和next指针都指向自己
	*pphead = BuyListNode(-1);
	(*pphead)->next = (*pphead)->prev = *pphead;
}*/

//销毁函数
void ListDestory(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* tmp = cur;
		cur = cur->next;
		free(tmp);
		tmp = NULL;
	}
	free(phead);
	phead = NULL;
}

//尾插函数
void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead); 
	//ListNode* newnode = BuyListNode(x);
	//ListNode* tail = phead->prev;//找到最后一个结点

	//newnode->prev = tail;//新结点的prev指向最后一个结点
	//newnode->next = phead;//新结点的next指向头结点
	//tail->next = newnode;//最后一个结点的next指向新结点
	//phead->prev = newnode;//头结点的prev指向新结点

	//或者
	ListInsert(phead, x);
}

//头插函数
void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);
	//ListNode* newnode = BuyListNode(x);
	//ListNode* first = phead->next;//找到第一个结点

	//newnode->next = first;
	//newnode->prev = phead;
	//first->prev = newnode;
	//phead->next = newnode;

	//或者
	ListInsert(phead->next, x);
}

//头删函数
void ListPopFront(ListNode* phead)
{
	assert(phead);
	////链表为空时不能删除（或者使用断言）
	//if (phead->next == phead)
	//	return;
	//else
	//{
	//	ListNode* first = phead->next;//找到第一个结点
	//	ListNode* second = first->next;//找到第二个结点

	//	phead->next = second;
	//	second->prev = phead;

	//	free(first);
	//	first = NULL;
	//}
	//或者
	ListErase(phead->next);
}

//尾删函数
void ListPopBack(ListNode* phead)
{
	assert(phead);
	////链表为空时不能删除（或者使用断言）
	//if (phead->next == phead)
	//	return;
	//else
	//{
	//	ListNode* tail = phead->prev;//找到最后一个结点
	//	ListNode* prev = tail->prev;//找到倒数第二个结点

	//	phead->prev = prev;
	//	prev->next = phead;

	//	free(tail);
	//	tail = NULL;
	//}
	//或者
	ListErase(phead->prev);
}

//查找函数
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	//链表为空时，返回NULL
	if (phead->next == phead)
		return NULL;
	else
	{
		ListNode* cur = phead->next;
		while (cur != phead)
		{
			if (cur->data == x)
				return cur;
			else
				cur = cur->next;
		}
		return NULL;
	}
}

//在pos位置前插入结点
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* newnode = BuyListNode(x);
	ListNode* prev = pos->prev;//找到前一个结点
	prev->next = newnode;
	pos->prev = newnode;
	newnode->prev = prev;
	newnode->next = pos;
}

//删除pos位置的结点
void ListErase(ListNode* pos)
{
	assert(pos);
	//如果该链表仅剩最后一个头结点，不能删除
	if (pos->next == pos)
		return;

	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	prev->next = next;
	next->prev = prev;

	free(pos);
	pos = NULL;
}

//判空函数
bool ListEmpty(ListNode* phead)
{
	if (phead->next == phead)
		return true;
	return false;
}