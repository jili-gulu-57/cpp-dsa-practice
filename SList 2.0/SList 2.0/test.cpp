#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

//测试尾插函数
void test01()
{
	SLTNode* phead = NULL;
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 4);
	SListPrint(phead);
}

//测试头插函数
void test02()
{
	SLTNode* phead = NULL;
	SListPushFront(&phead, 1);
	SListPushFront(&phead, 2);
	SListPushFront(&phead, 3);
	SListPushFront(&phead, 4);
	SListPrint(phead);
}

//测试尾删函数
void test03()
{
	SLTNode* phead = NULL;
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 4);
	SListPrint(phead);

	SListPopBack(&phead);
	SListPrint(phead);
	SListPopBack(&phead);
	SListPrint(phead);
	SListPopBack(&phead);
	SListPrint(phead);
}

//测试头删函数
void test04()
{
	SLTNode* phead = NULL;
	SListPushFront(&phead, 1);
	SListPushFront(&phead, 2);
	SListPushFront(&phead, 3);
	SListPushFront(&phead, 4);
	SListPrint(phead);

	SListPopFront(&phead);
	SListPrint(phead);
	SListPopFront(&phead);
	SListPrint(phead);
	SListPopFront(&phead);
	SListPrint(phead);
	SListPopFront(&phead);
	SListPrint(phead);
	SListPopFront(&phead);
	SListPrint(phead);
}

//测试查找函数
void test05()
{
	SLTNode* phead = NULL;
	SListPushFront(&phead, 1);
	SListPushFront(&phead, 2);
	SListPushFront(&phead, 3);
	SListPushFront(&phead, 4);
	SListPrint(phead);

	SLTNode* ret1 = SListFind(phead, 2);
	if (ret1 != NULL)
		printf("找到了\n");
	else
		printf("未找到\n");

	SLTNode* ret2 = SListFind(phead, 57);
	if (ret2 != NULL)
		printf("找到了\n");
	else
		printf("未找到\n");
}

//测试在指定结点之前插入
void test06()
{
	SLTNode* phead = NULL;
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 4);
	SListPrint(phead);

	//在第三个结点前插入57
	//先查找到第三个结点
	SLTNode* pos1 = SListFind(phead, 3);
	SListInsert(&phead, pos1, 57);
	SListPrint(phead);

	//在第一个结点前插入79
    //先查找到第一个结点
	SLTNode* pos2 = SListFind(phead, 1);
	SListInsert(&phead, pos2, 79);
	SListPrint(phead);

	//在最后一个结点前插入36
	//先查找到最后一个结点
	SLTNode* pos3 = SListFind(phead, 4);
	SListInsert(&phead, pos3, 36);
	SListPrint(phead);
}

//测试在指定结点之后插入
void test07()
{
	SLTNode* phead = NULL;
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 4);
	SListPrint(phead);

	//在第三个结点后插入57
    //先查找到第三个结点
	SLTNode* pos1 = SListFind(phead, 3);
	SListInsertAfter(&phead, pos1, 57);
	SListPrint(phead);

	//在第一个结点后插入79
	//先查找到第一个结点
	SLTNode* pos2 = SListFind(phead, 1);
	SListInsertAfter(&phead, pos2, 79);
	SListPrint(phead);

	//在最后一个结点后插入36
	//先查找到最后一个结点
	SLTNode* pos3 = SListFind(phead, 4);
	SListInsertAfter(&phead, pos3, 36);
	SListPrint(phead);
}

//测试删除结点函数
void test08()
{
	SLTNode* phead = NULL;
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 4);
	SListPrint(phead);

	//删除第一个结点
	SLTNode* pos1 = SListFind(phead, 1);
	SListErase(&phead, pos1);
	SListPrint(phead);

	//删除第三个结点
	SLTNode* pos2 = SListFind(phead, 3);
	SListErase(&phead, pos2);
	SListPrint(phead);

	//删除最后一个结点
	SLTNode* pos3 = SListFind(phead, 4);
	SListErase(&phead, pos3);
	SListPrint(phead);
}

//测试销毁函数
void test09()
{
	SLTNode* phead = NULL;
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 4);
	SListPrint(phead);

	SListDestory(&phead);
	SListPrint(phead);
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
	test09();
	return 0;
}