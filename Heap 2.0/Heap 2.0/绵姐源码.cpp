#define _CRT_SECURE_NO_WARNINGS 1
//#include"Heap.h"
//void HPInit(HP* php)
//{
//	assert(php);
//	php->arr = NULL;
//	php->size = php->capacity = 0;
//}
//void HPDestroy(HP* php)
//{
//	assert(php);
//	if (php->arr)
//		free(php->arr);
//
//	php->arr = NULL;
//	php->size = php->capacity = 0;
//}
////打印函数
//void HPPrint(HP* php)
//{
//	for (int i = 0; i < (php->size); i++)
//	{
//		printf("%d ", php->arr[i]);
//	}
//	printf("\n");
//}
//
//void Swap(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//
//void AdjustUp(HPDataType* arr, int child)
//{
//	int parent = (child - 1) / 2;
//
//	while (child > 0)//不需要等于，child只要走到根节点的位置，根节点没有父节点不需要交换
//	{
//		if (arr[child] < arr[parent])
//		{
//			Swap(&arr[parent], &arr[child]);
//			child = parent;
//			parent = (child - 1) / 2;
//		}
//		else
//		{
//			break;
//		}
//	}
//
//}
//
//void HPPush(HP* php, HPDataType x)
//{
//	assert(php);
//	//判断空间是否足够
//	if (php->size == php->capacity)
//	{
//		//扩容
//		int newCapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
//		HPDataType* tmp = (HPDataType*)realloc(php->arr, newCapacity * sizeof(HPDataType));
//		if (tmp == NULL)
//		{
//			perror("realloc fail!");
//			exit(1);
//		}
//		php->arr = tmp;
//		php->capacity = newCapacity;
//	}
//	php->arr[php->size] = x;
//
//	AdjustUp(php->arr, php->size);
//
//	++php->size;
//}
//
//void AdjustDown(HPDataType* arr, int parent, int n)
//{
//	int child = parent * 2 + 1;//左孩子
//	//while (parent < n)
//	while (child < n)
//	{
//		//找左右孩子中找最小的
//		if (child + 1 < n && arr[child] > arr[child + 1])
//		{
//			child++;
//		}
//		if (arr[child] < arr[parent])
//		{
//			Swap(&arr[child], &arr[parent]);
//			parent = child;
//			child = parent * 2 + 1;
//
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//
//void HPPop(HP* php)
//{
//	assert(php && php->size);
//
//	//arr[0]  arr[size-1]
//	Swap(&php->arr[0], &php->arr[php->size - 1]);
//
//	--php->size;
//
//	AdjustDown(php->arr, 0, php->size);
//
//
//}