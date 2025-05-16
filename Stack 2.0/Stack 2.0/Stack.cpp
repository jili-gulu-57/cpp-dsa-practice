#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

//初始化函数
void StackInit(ST* ps)
{
	assert(ps);

	ps->_arr = (STDataType*)malloc(sizeof(STDataType) * 4);//初始给4个STDataType大小的空间
	//检查是否成功申请空间
	if (!ps->_arr)
	{
		perror("malloc fail!");
		exit(1);
	}

	//走到这里说明申请成功
	ps->capacity = 4;
	ps->top = 0;
}

//销毁函数
void StackDestory(ST* ps)
{
	assert(ps);

	free(ps->_arr);
	ps->_arr = NULL;
	ps->capacity = ps->top = 0;
}

//入栈（插入函数）
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	//入栈前先检查容量
	if (ps->capacity == ps->top)
	{
		//一般二倍扩容
		STDataType* tmp = (STDataType*)realloc(ps->_arr, ps->capacity * 2 * sizeof(STDataType));
		//检查是否成功申请空间
		if (!tmp)
		{
			perror("realloc fail!");
			exit(1);//直接退出程序
		}

		//走到这里说明成功扩容
		ps->_arr = tmp;
		ps->capacity *= 2;
	}
	ps->_arr[ps->top] = x;
	ps->top++;
}

//出栈（删除函数）
void StackPop(ST* ps)
{
	assert(ps);

	//如果栈为空不能出栈
	if (ps->top == 0)
	{
		return;
	}
	else
		ps->top--;
}

//求栈顶元素
STDataType StackTop(ST* ps)
{
	assert(ps);

	//栈为空不能求栈顶元素
	assert(ps->top > 0);

	return ps->_arr[ps->top - 1];
}

//求数据个数
int StackSize(ST* ps)
{
	assert(ps);

	return ps->top;
}

//判空
bool StackEmpty(ST* ps)
{
	assert(ps);

	return ps->top == 0;//栈为空时返回true，不为空时返回false
}