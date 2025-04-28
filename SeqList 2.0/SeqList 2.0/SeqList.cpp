#define _CRT_SECURE_NO_WARNINGS 1
//包含自己写的头文件需用“”
#include"SeqList.h"

//初始化函数定义
void SeqListInit(SL* psl)//使用指针接收，否则形参的改变不会影响实参
{
	memset(psl->arr, 0, sizeof(SQDataType) * N);//将有N个数据大小为SQDataType的元素初始化为0
	psl->size = 0;
}

//尾插函数定义
void SeqListPushBack(SL* psl, SQDataType x)
{
	//处理数组满了的情况
	if (psl->size == N)
	{

	}

	//尾插时当前数据个数与要插入的位置下标是相同的
	psl->arr[psl->size] = x;
	psl->size++;
}

//头插函数定义
void SeqListPushFront(SL* psl, SQDataType x)
{

}