#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

//初始化
void HPInit(HP* php)
{
	//首先检查指针是否为空
	assert(php);

	php->arr = NULL;
	php->size = php->capacity = 0;
}

//销毁
void HPDestory(HP* php)
{
	assert(php);

	//数组不为空时,直接将数组置为空
	if (php->arr)
		free(php->arr);

	php->arr = NULL;
	php->size = php->capacity = 0;
}

//打印函数
void HPPrint(HP* php)
{
	for (int i = 0; i < (php->size); i++)
	{
		printf("%d ", php->arr[i]);
	}
	printf("\n");
}

//交换函数
void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

//向上调整算法
void AdjustUp(HPDataType* arr, int child)
{
	//根据孩子结点的下标计算出父结点的下标
	int parent = (child - 1) / 2;

	//child<0应该先判断，否则可能出现越界
	while (child > 0 && arr[child] < arr[parent])
	{
		Swap(&arr[child], &arr[parent]);

		//继续向上调整
		child = parent;
		parent = (child - 1) / 2;
	}
}

//插入数据
void HPPush(HP* php, HPDataType x)
{
	assert(php);

	//插入元素前要先判断空间是否足够
	if (php->size == php->capacity)
	{
		//空间不足先扩容
		//三目表达式,判断capacity是否为0,为0则给Newcapacity赋值为4,否则为二倍的capacity
		int Newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;

		HPDataType* tmp = (HPDataType*)realloc(php->arr, Newcapacity*sizeof(HPDataType));
		//检查空间申请是否成功
		if (tmp == NULL)
		{
			//打印错误信息
			perror("realloc fail!");
			exit(1);
		}

		php->arr = tmp;
		php->capacity = Newcapacity;
	}

	php->arr[php->size] = x;
	AdjustUp(php->arr, php->size);
	php->size++;
}

//向下调整算法
void AdjustDown(HPDataType* arr, int parent, int size)
{
	//根据父结点下标找到左、右孩子结点下标
	int leftchild = parent * 2 + 1;
	int minchild = 0;
	//防止出现右孩子为空但越界访问的问题
	if ((parent * 2 + 2) < size)
	{
		int rightchild = parent * 2 + 2;
		//找出左右结点较大的那个
		minchild = arr[leftchild] > arr[rightchild] ? leftchild : rightchild;
	}
	else
	{
		minchild = leftchild;
	}
	//用minchild作为循环结束的条件而不是parent
	//因为parent是叶子结点的时候已无法向下调整，因此当minchild>=size时，调整已结束
	while (minchild < size && arr[parent]<arr[minchild])
	{
		Swap(&arr[parent], &arr[minchild]);

		//继续向下调整
		parent = minchild;
		if ((minchild * 2 + 1) < size)
		{
			int leftchild = minchild * 2 + 1;
			int rightchild = minchild * 2 + 2;
			minchild = arr[leftchild] > arr[rightchild] ? leftchild : rightchild;
		}
	}
}

////绵姐源码
//void AdjustDown(HPDataType* arr, int parent, int size)
//{
//	int child = parent * 2 + 1;
//	while (child < size)
//	{
//		if (child + 1 < size && arr[child] > arr[child + 1])
//		{
//			child++;
//		}
//		if (arr[child] < arr[parent])
//		{
//			Swap(&arr[child], &arr[parent]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}

//删除数据
void HPPop(HP* php)
{
	assert(php);
	//同时要检查数组不能为空，为空不能删除数据
	assert(php->size);

	Swap(&php->arr[0], &php->arr[php->size - 1]);
	php->size--;
	AdjustDown(php->arr, 0, php->size);
}

//取堆顶数据
HPDataType HPTop(HP* php)
{
	//指针不能为空，同时数据个数不能为空
	assert(php && php->size);

	return php->arr[0];
}

//判断堆是否为空
bool HPEmpty(HP* php)
{
	assert(php);

	return php->size == 0;
}
