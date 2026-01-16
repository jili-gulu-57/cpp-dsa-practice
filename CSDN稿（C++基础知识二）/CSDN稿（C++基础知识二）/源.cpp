#include<iostream>
using namespace std;

////定义整型加法
//int Add1(int x, int y)
//{
//	return x + y;
//}
//
////定义浮点型加法
//double Add2(double x, double y)
//{
//	return x + y;
//}

//int Add(int x, int y)
//{
//	return x + y;
//}
//
////参数个数不同
//int Add(int x, int y, int z)
//{
//	return x + y + z;
//}
//
////参数类型不同
//double Add(double x, double y)
//{
//	return x + y;
//}
//
//int main()
//{
//	cout << Add(1, 2) << endl;
//	cout << Add(1, 2, 3) << endl;
//	cout << Add(1.1, 2.2) << endl;
//	return 0;
//}

//int Add(int x, int y)
//{
//	return x + y;
//}
//
//double Add(int x, int y)
//{
//	return x + y;
//}

int main()
{
	//int a = 10;
	//int& b = a;	//初始化
	//int& c;		//未初始化

	int a = 10;
	int& b = a;	//b是a的别名
	int& c = a;	//c也是a的别名

	cout << c;

	return 0;
}