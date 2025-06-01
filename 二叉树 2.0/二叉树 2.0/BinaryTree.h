#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"

typedef char BTDataType;
//二叉链
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* leftchild;
	struct BinaryTreeNode* rightchild;
}BTNode;

//三叉链
//typedef struct BinaryTreeNode
//{
//	BTDataType x;
//	struct BinaryTreeNode* leftchild;
//	struct BinaryTreeNode* rightchild;
//	struct BinaryTreeNode* parent;
//}BTNode;


//先序遍历
void PreOrder(BTNode* root);

//中序遍历
void InOrder(BTNode* root);

//后序遍历
void PostOrder(BTNode* root);

//层序遍历
void LevelOrder(BTNode* root);

//求二叉树结点个数
int BinaryTreeSize(BTNode* root);

//求二叉树叶子结点个数
int BinaryTreeLeafSize(BTNode* root);

//求二叉树第k层结点个数
int BinaryTreeLevelKSize(BTNode* root, int k);

//求二叉树的深度（高度）
int BinaryTreeDepth(BTNode* root);

//在二叉树中查找值为x的结点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

//二叉树的销毁
void BinaryTreeDestory(BTNode** root);

//判断二叉树是否为完全二叉树
bool BinaryTreeComplete(BTNode* root);