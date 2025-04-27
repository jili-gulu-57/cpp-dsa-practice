#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<memory>
using namespace std;

//C++标准库中智能指针都包含在<memory>头文件里，智能指针有好几种
//auto_ptr是C++98设计的，特点是把被拷贝对象的资源的管理权转移给拷贝对象，这会使得被拷贝对象被悬空，导致访问报错等问题
//C++11智能指针出来后强烈建议不要使用该指针
struct Date
{
	int _year;
	int _month;
	int _day;

	Date(int year=1,int month=1,int day=1)
		:_year(year)
		,_month(month)
		,_day(day)
	{}
	~Date()
	{
		cout << "~Date" << endl;
	}
};

template<class T>
void DeleteArrayfunc(T*ptr)
{
	delete[] ptr;
}

template<class T>
class DeleteArray
{
public:
	void operator()(T* ptr)
	{
		delete[]ptr;
	}
};
int main()
{
	//auto_ptr<Date> ap1(new Date);
	//auto_ptr<Date> ap2(ap1);
	//ap1已经悬空，访问会报错
	//ap1->_year++;

	//unique_ptr不支持拷贝，只支持移动，不需要拷贝的场合推荐使用
	//unique_ptr<Date> uq1(new Date);
	//unique_ptr<Date> uq2(uq1);

	////shared_ptr支持拷贝
	//shared_ptr<Date> sq1(new Date);
	//shared_ptr<Date> sq2(sq1);
	//shared_ptr<Date> sq3(sq1);
	////为防止多次析构，shared_ptr有计数器功能，只有最后一次时才析构
	//cout << sq1.use_count() << endl;

	//仿函数做删除器，unique_ptr和shared_ptr支持删除器的方式不同
	//unique_ptr<Date, DeleteArray<Date>> uq2(new Date[5]());
	//shared_ptr<Date> sp2(new Date[5], DeleteArray<Date>());

	//特化
	unique_ptr<Date[]> uq3(new Date[5]);
	shared_ptr<Date[]> sq3(new Date[5]);
	return 0;
}