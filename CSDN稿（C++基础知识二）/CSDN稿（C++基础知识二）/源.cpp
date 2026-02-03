#include<iostream>
using namespace std;

inline int ADD(int x, int y);	//声明

inline int ADD(int x, int y)	//定义
{
	return x + y;
}

int main()
{
	int sum = ADD(1, 2) * 3;
	//期望的结果是9，实际结果也是9

	cout << sum << endl;
	return 0;
}

//#define ADD(x,y) x+y




//int main()
//{
//	int sum = ADD(1, 2);//预处理后：int sum=(1+2);
//
//	cout << sum << endl;
//
//	return 0;
//}


//#define M 100
//
//int main()
//{
//	int a = M;
//	cout << a << endl;
//}


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

//int main()
//{
//	//int a = 10;
//	//int& b = a;	//初始化
//	//int& c;		//未初始化
//
//	int a = 10;
//	int& b = a;	//b是a的别名
//	int& c = a;	//c也是a的别名
//
//	cout << c;
//
//	return 0;
//}


//参数值加10的函数
//值传递
//void Func(int x)
//{
//	x += 10;
//}

//引用传递
//void Func(int& x)
//{
//	x += 10;
//}

	//指针传递
	/*void Func(int* x)
	{
		*x += 10;
	}*/

//int& Func(int x)
//{
//	return x += 10;
//}
//
//	int main()
//	{
//		//int a = 1;
//		//cout<<Func(a);	//调用函数
//
//		//double b = 1.1;
//		//int c = b;
//		//cout << c;
//
//		cout << sizeof(int*) << endl;
//		cout << sizeof(void*) << endl;
//		cout << sizeof(double*) << endl;
//		return 0;
//	}