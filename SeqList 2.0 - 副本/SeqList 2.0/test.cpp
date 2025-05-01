#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

//测试初始化函数
void test01()
{
	SL sl;
	SLInit(&sl);

	SLDestory(&sl);
}

//测试尾插函数
void test02()
{
	SL sl;
	SLInit(&sl);

	for (int i = 0; i < 10; i++)
	{
		SLPushBack(&sl, i);
	}
	SLPrint(&sl);

	SLDestory(&sl);
}

//测试头插函数
void test03()
{
	SL sl;
	SLInit(&sl);
	for (int i = 0; i < 10; i++)
	{
		SLPushFront(&sl, i);
	}
	SLPrint(&sl);

	SLDestory(&sl);
}

//测试指定位置插入
void test04()
{
	SL sl;
	SLInit(&sl);
	//先尾插五个数据
	for (int i = 0; i < 5; i++)
	{
		SLPushBack(&sl, i);
	}
	SLPrint(&sl);
	SLInsert(&sl, 87, 3);
	SLPrint(&sl);
	SLInsert(&sl, 56, 0);
	SLPrint(&sl);
	SLInsert(&sl, 16, 7);
	SLPrint(&sl);

	SLDestory(&sl);
}

//测试尾删函数
void test05()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPrint(&sl);

	SLPopBack(&sl);
	SLPrint(&sl);
	SLPopBack(&sl);
	SLPrint(&sl);
	SLPopBack(&sl);
	SLPrint(&sl);
	SLPopBack(&sl);
	SLPrint(&sl);
	SLPopBack(&sl);
	SLPrint(&sl);

	SLDestory(&sl);
}

//测试头删函数
void test06()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPrint(&sl);

	SLPopFront(&sl);
	SLPrint(&sl);
	SLPopFront(&sl);
	SLPrint(&sl);
	SLPopFront(&sl);
	SLPrint(&sl);
	SLPopFront(&sl);
	SLPrint(&sl);
	SLPopFront(&sl);
	SLPrint(&sl);

	SLDestory(&sl);
}

//测试指定位置删除
void test07()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPrint(&sl);

	SLErase(&sl, 1);
	SLPrint(&sl);
	SLErase(&sl, 0);
	SLPrint(&sl);
	SLErase(&sl, 2);
	SLPrint(&sl);

	SLDestory(&sl);
}

//测试查找函数
void test08()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPrint(&sl);

	printf("%d\n", SLFind(&sl, 3));
	printf("%d\n", SLFind(&sl, 1));
	printf("%d\n", SLFind(&sl, 5));
	printf("%d\n", SLFind(&sl, 79));

	SLDestory(&sl);
}

int main()
{
	//调用测试函数
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	test08();
	return 0;
}