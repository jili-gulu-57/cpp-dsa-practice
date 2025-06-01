#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"

//测试先序遍历
void test01()
{
	BTNode* n1 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n2 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n3 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n4 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n5 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n6 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n7 = (BTNode*)malloc(sizeof(BTNode));
	n1->data = 'A'; n1->leftchild = NULL; n1->rightchild = NULL;
	n2->data = 'B'; n2->leftchild = NULL; n2->rightchild = NULL;
	n3->data = 'C'; n3->leftchild = NULL; n3->rightchild = NULL;
	n4->data = 'D'; n4->leftchild = NULL; n4->rightchild = NULL;
	n5->data = 'E'; n5->leftchild = NULL; n5->rightchild = NULL;
	n6->data = 'F'; n6->leftchild = NULL; n6->rightchild = NULL;
	n7->data = 'G'; n7->leftchild = NULL; n7->rightchild = NULL;
	n1->leftchild = n2;
	n1->rightchild = n3;
	n2->leftchild = n4;
	n4->rightchild = n7;
	n3->leftchild = n5;
	n3->rightchild = n6;
	PreOrder(n1);
}

//测试中序遍历
void test02()
{
	BTNode* n1 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n2 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n3 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n4 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n5 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n6 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n7 = (BTNode*)malloc(sizeof(BTNode));
	n1->data = 'A'; n1->leftchild = NULL; n1->rightchild = NULL;
	n2->data = 'B'; n2->leftchild = NULL; n2->rightchild = NULL;
	n3->data = 'C'; n3->leftchild = NULL; n3->rightchild = NULL;
	n4->data = 'D'; n4->leftchild = NULL; n4->rightchild = NULL;
	n5->data = 'E'; n5->leftchild = NULL; n5->rightchild = NULL;
	n6->data = 'F'; n6->leftchild = NULL; n6->rightchild = NULL;
	n7->data = 'G'; n7->leftchild = NULL; n7->rightchild = NULL;
	n1->leftchild = n2;
	n1->rightchild = n3;
	n2->leftchild = n4;
	n4->rightchild = n7;
	n3->leftchild = n5;
	n3->rightchild = n6;
	InOrder(n1);
}

//测试后序遍历
void test03()
{
	BTNode* n1 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n2 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n3 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n4 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n5 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n6 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n7 = (BTNode*)malloc(sizeof(BTNode));
	n1->data = 'A'; n1->leftchild = NULL; n1->rightchild = NULL;
	n2->data = 'B'; n2->leftchild = NULL; n2->rightchild = NULL;
	n3->data = 'C'; n3->leftchild = NULL; n3->rightchild = NULL;
	n4->data = 'D'; n4->leftchild = NULL; n4->rightchild = NULL;
	n5->data = 'E'; n5->leftchild = NULL; n5->rightchild = NULL;
	n6->data = 'F'; n6->leftchild = NULL; n6->rightchild = NULL;
	n7->data = 'G'; n7->leftchild = NULL; n7->rightchild = NULL;
	n1->leftchild = n2;
	n1->rightchild = n3;
	n2->leftchild = n4;
	n4->rightchild = n7;
	n3->leftchild = n5;
	n3->rightchild = n6;
	PostOrder(n1);
}

//测试层序遍历
void test04()
{
	BTNode* n1 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n2 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n3 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n4 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n5 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n6 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n7 = (BTNode*)malloc(sizeof(BTNode));
	n1->data = 'A'; n1->leftchild = NULL; n1->rightchild = NULL;
	n2->data = 'B'; n2->leftchild = NULL; n2->rightchild = NULL;
	n3->data = 'C'; n3->leftchild = NULL; n3->rightchild = NULL;
	n4->data = 'D'; n4->leftchild = NULL; n4->rightchild = NULL;
	n5->data = 'E'; n5->leftchild = NULL; n5->rightchild = NULL;
	n6->data = 'F'; n6->leftchild = NULL; n6->rightchild = NULL;
	n7->data = 'G'; n7->leftchild = NULL; n7->rightchild = NULL;
	n1->leftchild = n2;
	n1->rightchild = n3;
	n2->leftchild = n4;
	n4->rightchild = n7;
	n3->leftchild = n5;
	n3->rightchild = n6;
	LevelOrder(n1);
}

//测试求结点个数
void test05()
{
	BTNode* n1 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n2 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n3 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n4 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n5 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n6 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n7 = (BTNode*)malloc(sizeof(BTNode));
	n1->data = 'A'; n1->leftchild = NULL; n1->rightchild = NULL;
	n2->data = 'B'; n2->leftchild = NULL; n2->rightchild = NULL;
	n3->data = 'C'; n3->leftchild = NULL; n3->rightchild = NULL;
	n4->data = 'D'; n4->leftchild = NULL; n4->rightchild = NULL;
	n5->data = 'E'; n5->leftchild = NULL; n5->rightchild = NULL;
	n6->data = 'F'; n6->leftchild = NULL; n6->rightchild = NULL;
	n7->data = 'G'; n7->leftchild = NULL; n7->rightchild = NULL;
	n1->leftchild = n2;
	n1->rightchild = n3;
	n2->leftchild = n4;
	n4->rightchild = n7;
	n3->leftchild = n5;
	n3->rightchild = n6;
	printf("结点个数为：%d ", BinaryTreeSize(n1));
}

//测试求叶子结点个数
void test06()
{
	BTNode* n1 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n2 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n3 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n4 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n5 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n6 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n7 = (BTNode*)malloc(sizeof(BTNode));
	n1->data = 'A'; n1->leftchild = NULL; n1->rightchild = NULL;
	n2->data = 'B'; n2->leftchild = NULL; n2->rightchild = NULL;
	n3->data = 'C'; n3->leftchild = NULL; n3->rightchild = NULL;
	n4->data = 'D'; n4->leftchild = NULL; n4->rightchild = NULL;
	n5->data = 'E'; n5->leftchild = NULL; n5->rightchild = NULL;
	n6->data = 'F'; n6->leftchild = NULL; n6->rightchild = NULL;
	n7->data = 'G'; n7->leftchild = NULL; n7->rightchild = NULL;
	n1->leftchild = n2;
	n1->rightchild = n3;
	n2->leftchild = n4;
	n4->rightchild = n7;
	n3->leftchild = n5;
	n3->rightchild = n6;
	printf("叶子结点个数为：%d ", BinaryTreeLeafSize(n2));
}

//测试求第k层结点个数
void test07()
{
	BTNode* n1 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n2 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n3 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n4 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n5 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n6 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n7 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n8 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n9 = (BTNode*)malloc(sizeof(BTNode));
	n1->data = 'A'; n1->leftchild = NULL; n1->rightchild = NULL;
	n2->data = 'B'; n2->leftchild = NULL; n2->rightchild = NULL;
	n3->data = 'C'; n3->leftchild = NULL; n3->rightchild = NULL;
	n4->data = 'D'; n4->leftchild = NULL; n4->rightchild = NULL;
	n5->data = 'E'; n5->leftchild = NULL; n5->rightchild = NULL;
	n6->data = 'F'; n6->leftchild = NULL; n6->rightchild = NULL;
	n7->data = 'G'; n7->leftchild = NULL; n7->rightchild = NULL;
	n8->data = 'H'; n8->leftchild = NULL; n8->rightchild = NULL;
	n9->data = 'I'; n9->leftchild = NULL; n9->rightchild = NULL;
	n1->leftchild = n2;
	n1->rightchild = n3;
	n2->leftchild = n4;
	n2->rightchild = n8;
	n4->rightchild = n7;
	n3->leftchild = n5;
	n3->rightchild = n6;
	n7->leftchild = n9;
	printf("第%d层结点个数为：%d ", 4,BinaryTreeLevelKSize(n1,4));
}

//测试求二叉树的深度
void test08()
{
	BTNode* n1 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n2 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n3 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n4 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n5 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n6 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n7 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n8 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n9 = (BTNode*)malloc(sizeof(BTNode));
	n1->data = 'A'; n1->leftchild = NULL; n1->rightchild = NULL;
	n2->data = 'B'; n2->leftchild = NULL; n2->rightchild = NULL;
	n3->data = 'C'; n3->leftchild = NULL; n3->rightchild = NULL;
	n4->data = 'D'; n4->leftchild = NULL; n4->rightchild = NULL;
	n5->data = 'E'; n5->leftchild = NULL; n5->rightchild = NULL;
	n6->data = 'F'; n6->leftchild = NULL; n6->rightchild = NULL;
	n7->data = 'G'; n7->leftchild = NULL; n7->rightchild = NULL;
	n8->data = 'H'; n8->leftchild = NULL; n8->rightchild = NULL;
	n9->data = 'I'; n9->leftchild = NULL; n9->rightchild = NULL;
	n1->leftchild = n2;
	n1->rightchild = n3;
	n2->leftchild = n4;
	n2->rightchild = n8;
	n4->rightchild = n7;
	n3->leftchild = n5;
	n3->rightchild = n6;
	n7->leftchild = n9;
	printf("该二叉树有%d层", BinaryTreeDepth(n1));
}

//测试查找函数
void test09()
{
	BTNode* n1 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n2 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n3 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n4 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n5 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n6 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n7 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n8 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n9 = (BTNode*)malloc(sizeof(BTNode));
	n1->data = 'A'; n1->leftchild = NULL; n1->rightchild = NULL;
	n2->data = 'B'; n2->leftchild = NULL; n2->rightchild = NULL;
	n3->data = 'C'; n3->leftchild = NULL; n3->rightchild = NULL;
	n4->data = 'D'; n4->leftchild = NULL; n4->rightchild = NULL;
	n5->data = 'E'; n5->leftchild = NULL; n5->rightchild = NULL;
	n6->data = 'F'; n6->leftchild = NULL; n6->rightchild = NULL;
	n7->data = 'G'; n7->leftchild = NULL; n7->rightchild = NULL;
	n8->data = 'H'; n8->leftchild = NULL; n8->rightchild = NULL;
	n9->data = 'I'; n9->leftchild = NULL; n9->rightchild = NULL;
	n1->leftchild = n2;
	n1->rightchild = n3;
	n2->leftchild = n4;
	n2->rightchild = n8;
	n4->rightchild = n7;
	n3->leftchild = n5;
	n3->rightchild = n6;
	n7->leftchild = n9;
	
	BTNode* ret1 = BinaryTreeFind(n1, 'I');//查找值为I的结点
	if (ret1)
		printf("找到了,存在值为‘I’的结点\n");
	else
		printf("未找到，不存在值为‘I’的结点\n");

	BTNode* ret2 = BinaryTreeFind(n1, 'Z');//查找值为I的结点
	if (ret2)
		printf("找到了,存在值为‘Z’的结点\n");
	else
		printf("未找到，不存在值为‘Z’的结点\n");
}

//测试二叉树的销毁
void test10()
{
	BTNode* n1 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n2 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n3 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n4 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n5 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n6 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n7 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n8 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n9 = (BTNode*)malloc(sizeof(BTNode));
	n1->data = 'A'; n1->leftchild = NULL; n1->rightchild = NULL;
	n2->data = 'B'; n2->leftchild = NULL; n2->rightchild = NULL;
	n3->data = 'C'; n3->leftchild = NULL; n3->rightchild = NULL;
	n4->data = 'D'; n4->leftchild = NULL; n4->rightchild = NULL;
	n5->data = 'E'; n5->leftchild = NULL; n5->rightchild = NULL;
	n6->data = 'F'; n6->leftchild = NULL; n6->rightchild = NULL;
	n7->data = 'G'; n7->leftchild = NULL; n7->rightchild = NULL;
	n1->leftchild = n2;
	n1->rightchild = n3;
	n2->leftchild = n4;
	n4->rightchild = n7;
	n3->leftchild = n5;
	n3->rightchild = n6;

	BinaryTreeDestory(&n1);
}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	//test08();
	//test09();
	test10();
	return 0;
}