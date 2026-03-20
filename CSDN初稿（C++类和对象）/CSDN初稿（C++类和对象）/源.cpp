#include<iostream>
#include<string>
#include<vector>
using namespace std;

//struct Student
//{
//	char name[20];  //姓名
//	char num[20];   //学号
//	int age;	    //年龄
//	char sex;		//性别
//	
//	void Study()
//	{
//		//……学习
//	}
//
//	void Eat()
//	{
//		//……吃饭
//	}
//};

class BankAccount
{
public:
	//构造函数
	BankAccount()
	{
	}

	//存款
	void deposit(int money)
	{
		cout << "存款..." << endl;
		_balance += money;
	}

	//取款
	void withdraw(int money)
	{
		cout << "取款..." << endl;
		_balance -= money;
	}

	//查询余额
	void ShowBalance()
	{
		cout << "余额为：" << this->_balance << endl;
	}

	//析构函数
	~BankAccount()
	{
	}
private:
	string _name;		//户主姓名
	vector<int> _number;//账号
	string _password;   //密码
	int _balance;//余额
};

int main()
{
	BankAccount p1,p2;
	p1.deposit(100);
	p2.deposit(200);

	cout << "p1";
	p1.ShowBalance();

	cout << "p2";
	p2.ShowBalance();

	return 0;
}

//class test
//{
//public:
//	test()
//	{ }
//	~test()
//	{ }
//
//private:
//	int a;
//	char b;
//	double c;
//};
//
//class test2
//{
//public:
//	test2()
//	{ }
//	~test2()
//	{ }
//};
//
//class test3
//{
//
//};
	//cout << "类test2的大小为：" << sizeof(test2) << endl;
	//cout << "类test3的大小为：" << sizeof(test3) << endl;
