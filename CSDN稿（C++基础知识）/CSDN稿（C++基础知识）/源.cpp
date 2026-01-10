#include<iostream>
using  namespace std;

//定义一个整型加法函数
//int Sum(int x=1,int y=2,int z=3)
//{
//	return x + y + 3;
//}
//
////正确写法：
//void func(int x = 1, int y = 2, int z = 3);
//void func(int x, int y = 2, int z = 3);
//void func(int x, int y, int z = 3);
//
////错误写法：
//void func(int x = 1, int y = 2, int z);
//void func(int x = 1, int y, int z = 3);
//
//
//int main()
//{
//
//	return 0;
//}

//int main()
//{
//	int m1 = Sum();		 //可以不传参
//	int m2 = Sum(10);	 //给x传参
//	int m3 = Sum(10, 20);//给x、y传参
//
//	cout << m1 << endl;	 //输出m1
//	cout << m2 << endl;	 //输出m1
//	cout << m3 << endl;	 //输出m1
//
//	return 0;
//}

//int Sum(int x=0, int y=0)
//{
//	return x + y;
//}
//
//int main()
//{
//	int x;
//	float y;
//	string s;
//
//	cin >> x;	//输入整数
//	cin >> y;	//输入浮点数
//	cin >> s;	//输入字符串
//
//	//或者直接写出下面格式
//	//cin >> x >> y >> s;
//
//	cout << x <<" " << y <<" " << s << endl;
//
//	return 0;
//}


//int main()
//{
//	cout << "hello world!" << endl;
//	cerr << "111111";
//	return 0;
//}

//int main()
//{
//	std::string s = "hello world!";
//	cout << s;
//	return 0;
//}


//int max(int a, int b)
//{
//	return a >= b ? a : b;
//}
//
//int max = 1;

//int x = 10;	//全局变量

//int main()
//{
//	int x = 20;	//局部变量
//	int y = 30;
//
//	cout << ::x + y << endl;	//::x表示使用全局变量
//	return 0;
//}

//namespace zs
//{
//	int a = 1;
//	int b = 2;
//	int Sum(int x, int y)
//	{
//		return x + y;
//	}
//
//	namespace ls
//	{
//		int Sub(int x, int y)
//		{
//			return x - y;
//		}
//	}
//}



namespace wq
{
	int a = 1;
	int b = 2;
}

int main()
{
	int a = 10;
	int b = 20;
	int sum1 = wq::a + wq::b;
	int sum2 = a + b;
	cout << "wq作用域内a、b和为：" << sum1 << endl;
	cout << "局部域内a、b和为：" << sum2 << endl;
}