#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>

typedef int QDataType;

typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;

//初始化函数
void QueueInit(Queue* pq);

//销毁函数
void QueueDestory(Queue* pq);

//入队列函数
void QueuePush(Queue* pq, QDataType x);

//出队列函数
void QueuePop(Queue* pq);

//取队头数据
QDataType QueueFront(Queue* pq);

//取队尾数据
QDataType QueueBack(Queue* pq);

//求队长（数据个数）
int QueueSize(Queue* pq);

//判空
bool QueueEmpty(Queue* pq);