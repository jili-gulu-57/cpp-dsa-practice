#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//包扩展
//对于一个参数包，除了能计算参数个数，还能扩展它，就是将包分解为构成它的每个元素
//void ShowList()
//{
//	cout << endl;
//}
//template<class T, class ...Args>
//void ShowList(T x, Args...args)
//{
//	cout << x << " ";
//	ShowList(args...);
//}
////编译时递归推导解析参数
//template<class ...Args>
//void Print(Args...args)
//{
//	ShowList(args...);
//}
//
//int main()
//{
//	Print();
//	Print(2);
//	Print(3,"hello");
//	Print(4,"world",2.7);
//	return 0;
//}


//包装器functional和bind
#include<functional>
//int f(int a, int b)
//{
//	return a + b;
//}
//
//struct Functor
//{
//public:
//	int operator()(int a, int b)
//	{
//		return a + b;
//	}
//};
//
//class Plus
//{
//public:
//	Plus(int n=10)
//		:_n(n)
//	{}
//	static int plusi(int a, int b)
//	{
//		return a + b;
//	}
//	double plusd(double a, double b)
//	{
//		return (a + b) * _n;
//	}
//private:
//	int _n;
//};
//int main()
//{
//	//包装各种可调用对象
//	//第一个int为返回值，第二、三个是参数类型
//	function<int(int, int)> f1 = f;
//	function<int(int, int)> f2 = Functor();
//	function<int(int, int)> f3 = [](int a, int b) {return a + b; };
//	cout << f1(1, 2) << endl;
//	cout << f2(3, 4) << endl;
//	cout << f3(5, 6) << endl;
//	//包装静态成员函数，需指定类域，并且需要&才能获得地址
//	function<int(int, int)> f4 = &Plus::plusi;
//	cout << f4(7, 8) << endl;
//	return 0;
//}

//bind是一个函数模板，可以用来调整参数个数和参数顺序，也包含在<functional>文件里。
int Sub(int a, int b)
{
	return (a - b) * 10;
}

int Subx(int a, int b, int c)
{
	return (a - b - c) * 10;
}

using placeholders::_1;
using placeholders::_2;
using placeholders::_3;

int main()
{
	//调整顺序
	//_1永远代表第一个参数，_2永远代表第二个参数
	auto sub1 = bind(Sub, _1, _2);
	cout << sub1(10, 5) << endl;

	auto sub2 = bind(Sub, _2, _1);
	cout << sub2(10, 5) << endl;

	//调整个数（常用）
	auto sub3 = bind(Sub, 100, _1);//绑定固定参数
	cout << sub3(5) << endl;
}
