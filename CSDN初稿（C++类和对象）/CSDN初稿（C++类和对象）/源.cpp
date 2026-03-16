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
	{}

	//存款
	void deposit()
	{
		cout << "存款..." << endl;
	}

	//取款
	void withdraw()
	{
		cout << "取款..." << endl;
	}

	//查询余额
	void ShowBalance()
	{
		cout << "余额为：" << _balance << endl;
	}

	//析构函数
	~BankAccount()
	{}
private:
	string _name;		//户主姓名
	vector<int> _number;//账号
	string _password;   //密码
	vector<int> _balance;//余额
};

int main()
{
	return 0;
}