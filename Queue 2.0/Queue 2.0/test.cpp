#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

//测试各个函数功能
void test()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	QueueDestory(&q);
}

int main()
{
	test();
	return 0;
}