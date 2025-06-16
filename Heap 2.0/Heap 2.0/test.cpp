#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

void test01()
{
	Heap hp;
	HPInit(&hp);

	//≤‚ ‘≤Â»Î∫Ø ˝
	HPPush(&hp, 1);
	HPPush(&hp, 7);
	HPPush(&hp, 14);
	HPPush(&hp, 3);
	HPPush(&hp, 2);
	HPPush(&hp, 9);
	//HPPush(&hp, 90);
	//HPPush(&hp, 1);
	HPPrint(&hp);

	HPPop(&hp);
	HPPrint(&hp);
	HPPop(&hp);
	HPPrint(&hp);
	HPPop(&hp);
	HPPrint(&hp);
	HPPop(&hp);
	HPPrint(&hp);

	//≤‚ ‘»°∂—∂•∫Õ…æ≥˝∫Ø ˝
	//while (!HPEmpty(&hp))
	//{
	//	printf("%d ", HPTop(&hp));
	//	HPPop(&hp);
	//}

	HPDestory(&hp);
}

int main()
{
	test01();
	return 0;
}