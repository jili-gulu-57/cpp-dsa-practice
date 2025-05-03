#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

//打印函数（方便调试）
void SListPrint(SLTNode* phead)
{
	assert(phead);
	SLTNode* cur = phead;
	while (cur != NULL)//循环结束走到空结点
	{
		printf(" %d ->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//申请新结点
SLTNode* BuySListNode(SLDataType x)
{
	SLTNode* NewNode = (SLTNode*)malloc(sizeof(SLTNode));
	NewNode->data = x;
	NewNode->next = NULL;
	return NewNode;
}

//尾插函数
//需要传二级指针，否则形参的改变不影响实参
void SListPushBack(SLTNode** pphead, SLDataType x)
{
	assert(pphead);//不能传空地址，否则解引用找链表头结点会报错
	//创建新结点
	SLTNode* NewNode = BuySListNode(x);

	//链表为空，直接插入
	if (*pphead == NULL)
	{
		*pphead = NewNode;
	}
	else
	{
		//需要找到最后一个结点才能尾插，因此先用一个cur结点标记当前所在位置
		SLTNode* cur = *pphead;
		while (cur->next != NULL)//循环结束走到最后一个结点
		{
			cur = cur->next;//让cur遍历到最后一个结点
		}

		if (NewNode == NULL)
		{
			perror("malloc fail!");
			exit(1);
		}
		cur->next = NewNode;
	}
}

//头插函数
void SListPushFront(SLTNode** pphead, SLDataType x)
{
	assert(pphead);
	//创建新结点
	SLTNode* NewNode = BuySListNode(x);

	NewNode->next = *pphead;
	*pphead = NewNode;
}

//尾删函数
void SListPopBack(SLTNode** pphead)
{
	assert(pphead && *pphead);
	//如果只有一个结点
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* cur = *pphead;
		while (cur->next->next != NULL)//需要找到倒数第二个结点才能删除最后一个结点
		{
			cur = cur->next;
		}
		SLTNode* tmp = cur->next;
		free(tmp);
		tmp = NULL;
		cur->next = NULL;
	}
}

//头删函数
void SListPopFront(SLTNode** pphead)
{
	assert(pphead&&*pphead);//链表为空时不能删除
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

//在指定结点之前插入函数
void SListInsert(SLTNode** pphead, SLTNode* pos, SLDataType x)
{
	assert(pphead && *pphead);
	assert(pos);
	//需要找到指定结点的前一个结点
	SLTNode* prev = *pphead;
	//可能第一个结点就是指定结点，此时相当于头插
	if (prev == pos)
	{
		//直接调用头插函数
		SListPushFront(pphead, x);
	}
	else
	{
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		SLTNode* NewNode = BuySListNode(x);
		NewNode->next = prev->next;
		prev->next = NewNode;
	}
}

//在指定结点之后插入函数
void SListInsertAfter(SLTNode** pphead, SLTNode* pos, SLDataType x)
{
	assert(pphead && *pphead);
	assert(pos);
	SLTNode* NewNode = BuySListNode(x);
	NewNode->next = pos->next;
	pos->next = NewNode;
}

//删除指定结点
void SListErase(SLTNode** pphead, SLTNode* pos)
{
	SLTNode* prev = *pphead;
	//如果第一个结点就是要删除的结点
	if (prev == pos)
	{
		//直接调用头删
		SListPopFront(pphead);
	}
	else
	{
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		SLTNode* tmp = prev->next;//tmp即要删除的结点
		prev->next = tmp->next;
		free(tmp);
		tmp = NULL;
	}
}

//查找
SLTNode* SListFind(SLTNode* phead, SLDataType x)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	//没找到或链表为空时，返回空指针
	return NULL;
}

//销毁链表函数
void SListDestory(SLTNode** pphead)
{
	assert(pphead && *pphead);
	while (*pphead != NULL)
	{
		SLTNode* tmp = *pphead;
		*pphead = (*pphead)->next;
		free(tmp);
		tmp = NULL;
	}
}