#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* _arr; //数组
	int top;          //栈顶
	int capacity;     //容量大小
}ST;

//初始化函数
void StackInit(ST* ps);

//销毁函数
void StackDestory(ST* ps);

//入栈（插入函数）
void StackPush(ST* ps, STDataType x);

//出栈（删除函数）
void StackPop(ST* ps);

//求栈顶元素
STDataType StackTop(ST* ps);

//求数据个数
int StackSize(ST* ps);

//判空
bool StackEmpty(ST* ps);