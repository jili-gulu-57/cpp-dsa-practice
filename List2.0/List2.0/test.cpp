#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

//测试初始化函数
void test01()
{
	ListNode* phead = ListInit();
	PrintList(phead);
	ListDestory(phead);
}

//测试尾插函数
void test02()
{
	ListNode* phead = ListInit();
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	PrintList(phead);
	ListDestory(phead);
}

//测试头插函数
void test03()
{
	ListNode* phead = ListInit();
	ListPushFront(phead, 1);
	ListPushFront(phead, 2);
	ListPushFront(phead, 3);
	ListPushFront(phead, 4);
	PrintList(phead);
	ListDestory(phead);
}

//测试头删函数
void test04()
{
	ListNode* phead = ListInit();
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	PrintList(phead);

	ListPopFront(phead);
	PrintList(phead);
	ListPopFront(phead);
	PrintList(phead);
	ListPopFront(phead);
	PrintList(phead);
	ListPopFront(phead);
	PrintList(phead);
	ListPopFront(phead);
	PrintList(phead);
	ListDestory(phead);
}

//测试尾删函数
void test05()
{
	ListNode* phead = ListInit();
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	PrintList(phead);

	ListPopBack(phead);
	PrintList(phead);
	ListPopBack(phead);
	PrintList(phead);
	ListPopBack(phead);
	PrintList(phead);
	ListPopBack(phead);
	PrintList(phead);
	ListPopBack(phead);
	PrintList(phead);
	ListDestory(phead);
}

//测试查找函数
void test06()
{
	ListNode* phead = ListInit();
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	PrintList(phead);

	//查找是否有值为1的结点
	if (ListFind(phead,1) != NULL)
	{
		printf("存在值为1的结点\n");
	}
	else
	{
		printf("不存在值为1的结点\n");
	}
	
	//查找是否有值为57的结点
	if (ListFind(phead, 57) != NULL)
	{
		printf("存在值为57的结点\n");
	}
	else
	{
		printf("不存在值为57的结点\n");
	}
	ListDestory(phead);
}

//测试在结点前插入函数
void test07()
{
	ListNode* phead = ListInit();
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	PrintList(phead);

	//在第三个结点前插入300（首先找到第三个结点）
	ListNode* pos1 = ListFind(phead, 3);
	ListInsert(pos1, 300);
	PrintList(phead);

	//在第1个结点前插入100（首先找到第1个结点）
	ListNode* pos2 = ListFind(phead, 1);
	ListInsert(pos2, 100);
	PrintList(phead);

	//在最后一个结点前插入400（首先找到最后一个结点）
	ListNode* pos3 = ListFind(phead, 4);
	ListInsert(pos3, 400);
	PrintList(phead); 
	ListDestory(phead);
}

//测试删除pos结点
void test08()
{
	ListNode* phead = ListInit();
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	PrintList(phead);

	////删除值为1的结点（首先先找到值为1的结点）
	ListNode* pos1 = ListFind(phead, 1);
	ListErase(pos1);
	PrintList(phead);

	////删除值为3的结点（首先先找到值为3的结点）
	ListNode* pos2 = ListFind(phead, 3);
	ListErase(pos2);
	PrintList(phead);

	//删除值为4的结点（首先先找到值为4的结点）
	ListNode* pos3 = ListFind(phead, 4);
	ListErase(pos3);
	PrintList(phead);
	ListDestory(phead);
}

//测试判空函数
void test09()
{
	ListNode* phead = ListInit();
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	PrintList(phead);

	if (ListEmpty(phead))
		printf("链表为空\n");
	else
		printf("链表不为空\n");

	ListNode* phead2 = ListInit();

	if (ListEmpty(phead2))
		printf("链表为空\n");
	else
		printf("链表不为空\n");
	ListDestory(phead);
	ListDestory(phead2);
}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	//test08();
	//test09();
	return 0;
}