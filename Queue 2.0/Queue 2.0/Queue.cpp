#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

//初始化函数
void QueueInit(Queue* pq)
{
	assert(pq);

	pq->head = pq->tail = NULL;
}

//销毁函数
void QueueDestory(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}

//入队列函数
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	//处理申请空间失败的情况
	if (newnode == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;

	//队列为空时，将头尾指针指向同一个结点
	if (pq->head == NULL)
		pq->head = pq->tail = newnode;
	else
	{
		//先将新结点链接到队列的队尾
		pq->tail->next = newnode;
		//再将尾指针指向新结点
		pq->tail = newnode;
	}
}

//出队列函数
void QueuePop(Queue* pq)
{
	assert(pq);
	
	//队列为空时不能出数据（或者使用断言）
	if (pq->head == NULL)
	{
		return;
	}
	else
	{
		//先记录头指针的下一个结点
		//需要先判断下一个结点是不是空
		if (pq->head->next == NULL)
		{
			free(pq->head);
			pq->head = pq->tail = NULL;
		}
		else
		{
			QNode* next = pq->head->next;

			//释放头指针指向的结点
			free(pq->head);
			//将头指针指向下一个结点，成为新的队头
			pq->head = next;
		}
	}
}

//取队头数据
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);//队为空不能取数据

	return pq->head->data;
}

//取队尾数据
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->head);//队为空不能取数据

	return pq->tail->data;
}

//求队长（数据个数）
int QueueSize(Queue* pq)
{
	assert(pq);

	int size = 0;
	QNode* cur = pq->head;
	while (cur != NULL)
	{
		size++;
		cur = cur->next;
	}
	return size;
}

//判空
bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->head == NULL;//队列为空返回true，否则返回false
}