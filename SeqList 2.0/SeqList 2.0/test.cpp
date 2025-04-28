#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

//测试初始化函数
void test01()
{
	SL sl;
	SeqListInit(&sl);
}

//测试尾插函数
void test02()
{
	SL sl;
	SeqListInit(&sl);

	for (int i = 0; i < 10; i++)
	{
		SeqListPushBack(&sl, i);
	}
}

int main()
{
	//调用测试函数
	//test01();
	test02();
	return 0;
}