#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"

//先序遍历
void PreOrder(BTNode* root)
{
	//根结点为空，即树为空时，直接返回
	if (root == NULL)
		return;

	printf("%c ", root->data);  //遍历根结点
	PreOrder(root->leftchild);  //遍历左子树
	PreOrder(root->rightchild); //遍历右子树
	
}

//中序遍历
void InOrder(BTNode* root)
{
	if (root == NULL)
		return;

	InOrder(root->leftchild);//先遍历左子树
	printf("%c ", root->data);//然后是根
	InOrder(root->rightchild);//最后是右子树
}

//后序遍历
void PostOrder(BTNode* root)
{
	if (root == NULL)
		return;

	PostOrder(root->leftchild); //先遍历左子树
	PostOrder(root->rightchild);//再遍历右子树
	printf("%c ", root->data);  //最后遍历根结点
}

//层序遍历
void LevelOrder(BTNode* root)
{
	//借助队列完成
	Queue q;
	QueueInit(&q);
	if (root == NULL)
		return;

	QueuePush(&q, root);
	while (QueueSize(&q))
	{
		BTNode* tmp = QueueFront(&q);
		QueuePop(&q);
		if (tmp->leftchild)
			QueuePush(&q, tmp->leftchild);
		if (tmp->rightchild)
			QueuePush(&q, tmp->rightchild);
		printf("%c ", tmp->data);
	}
}

//求二叉树结点个数
//分治思想
int BinaryTreeSize(BTNode* root)
{
	//采用三目表达式，结点为空直接返回，否则递归计算左右子树个数及根结点。
	return root == NULL ? 0 : BinaryTreeSize(root->leftchild) + BinaryTreeSize(root->rightchild) + 1;
}

//void BinaryTreeSize(BTNode* root,int *psize)
//{
//	//根据遍历求个数
//	if (root == NULL)
//		return ;
//	else
//	{
//		(*psize)++;
//	}
//	BinaryTreeSize(root->leftchild, psize);
//	BinaryTreeSize(root->rightchild, psize);
//	
//}

//求二叉树叶子结点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->leftchild==NULL&&root->rightchild==NULL)
		return 1;

	return BinaryTreeLeafSize(root->leftchild) + BinaryTreeLeafSize(root->rightchild);
}

//求二叉树第k层结点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return BinaryTreeLevelKSize(root->leftchild, k-1) + BinaryTreeLevelKSize(root->rightchild, k-1);
}

//求二叉树的深度（高度）
int BinaryTreeDepth(BTNode* root)
{
	if (root == NULL)
		return 0;

	int leftdepth = BinaryTreeDepth(root->leftchild);
	int rightdepth = BinaryTreeDepth(root->rightchild);
	return leftdepth > rightdepth ? leftdepth + 1 : rightdepth + 1;
}

//在二叉树中查找值为x的结点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;

	BTNode* left = BinaryTreeFind(root->leftchild,x);
	if (left)
		return left;

	BTNode* right = BinaryTreeFind(root->rightchild,x);
	if (right)
		return right;

	return NULL;
}

//二叉树的销毁
void BinaryTreeDestory(BTNode** root)
{
	//根据 左->右->根 的顺序销毁二叉树
	if (*root == NULL)
		return;

	 BinaryTreeDestory(&(*root)->leftchild);
	 BinaryTreeDestory(&(*root)->rightchild);
	
	free(*root);
	*root = NULL;

}

//判断二叉树是否为完全二叉树
bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root == NULL)
		return true;
	QueuePush(&q,root);
	while (QueueSize(&q))
	{
		BTNode* tmp = QueueFront(&q);
		QueuePop(&q);
		if (tmp == NULL)
			break;

		QueuePush(&q,tmp->leftchild);
		QueuePush(&q, tmp->rightchild);
	}
	while (QueueSize(&q))
	{
		BTNode* tmp = QueueFront(&q);
		if (tmp != NULL)
			return false;
	}
	return true;
}
