#define _CRT_SECURE_NO_WARNINGS 1
//包含自己写的头文件需用“”
#include"SeqList.h"

//初始化函数定义
void SLInit(SL* ps)//使用指针接收，否则形参的改变不会影响实参
{
	ps->arr = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

//销毁函数定义
void SLDestory(SL* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->capacity = ps->size = 0;
}

//打印顺序表（方便调试）
void SLPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}

//检查空间是否充足（其他插入函数也需要检查空间是否充足，因此直接封装为一个函数）
void SLCheckCapacity(SL* ps)
{
	//处理数组满了的情况
	if (ps->size == ps->capacity)
	{
		//如果当前顺序表容量大小为0，那么乘2也为0，所以用三目操作符判断。一般是二倍扩容
		int NewCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;

		//防止出现扩容失败造成数据丢失，因此先用tmp暂存
		SQDataType* tmp = (SQDataType*)realloc(ps->arr, NewCapacity * sizeof(SQDataType));
		if (tmp == NULL)
		{
			printf("realloc fail!");
			exit(1);
		}
		ps->arr = tmp;
		ps->capacity = NewCapacity;
	}
}

//尾插函数定义
//时间复杂度为O(1)
void SLPushBack(SL* ps, SQDataType x)
{
	//使用断言检查指针是否为空
	assert(ps);
	SLCheckCapacity(ps);
	//尾插时当前数据个数与要插入的位置下标是相同的
	ps->arr[ps->size] = x;
	ps->size++;
}


//头插函数定义
//时间复杂度为O(n)
void SLPushFront(SL* ps, SQDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);

	//头插时先要把数据整体后移(先移动后面的数据)
	for (int i = ps->size - 1; i >= 0; i--)
	{
		ps->arr[i + 1] = ps->arr[i];
	}
	ps->arr[0] = x;
	ps->size++;
}

//指定位置插入函数定义
//时间复杂度为O(n)
void SLInsert(SL* ps, SQDataType x, int pos)
{
	assert(ps);
	//检查指定位置的有效性
	assert(pos >= 0 && pos <= ps->size);
	SLCheckCapacity(ps);

	//要将指定位置及之后的数据整体往后移
	for (int i = ps->size - 1; i >=pos;i--)
	{
		ps->arr[i + 1] = ps->arr[i];
	}
	ps->arr[pos] = x;
	ps->size++;
}

//尾删函数定义
//时间复杂度为O(1)
void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size);//数据个数为0时不能删除
	ps->size--;
}

//头删函数定义
//时间复杂度为O(n)
void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size);
	//所有数据整体向前移动一位即头删
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

//删除指定位置的数据
//时间复杂度为O(n)
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(ps->size);
	assert(pos >= 0 && pos < ps->size);

	//pos位置之后的数据整体向前移即完成删除
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

//查找指定数据
//时间复杂度为O(n)
int SLFind(SL* ps, SQDataType x)
{
	assert(ps);
	assert(ps->size);

	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x)
			return i;//查找成功返回下标
	}
	//循环结束仍未返回，则代表没有该数据，查找失败返回-1
	return -1;
}