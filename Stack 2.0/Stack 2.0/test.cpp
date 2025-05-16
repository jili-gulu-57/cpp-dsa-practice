#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

//测试各个函数
void test01()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	//入栈后依次取栈顶数据观察
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		//取完栈顶元素后出栈，这样下次才能取到后续的元素
		StackPop(&st);
	}

	StackDestory(&st);
}

int main()
{
	test01();
	return 0;
}