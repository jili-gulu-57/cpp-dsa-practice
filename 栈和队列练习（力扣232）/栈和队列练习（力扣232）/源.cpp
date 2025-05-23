#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stack>
using namespace std;

//已通过
//注意栈来回倒的话数据的顺序可能会改变，并且再插入数据顺序也会乱，因此倒完一次要再倒。
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {

    }

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        int tmp = 0;
        while (s1.size() != 1)
        {
            tmp = s1.top();
            s1.pop();
            s2.push(tmp);
        }
        tmp = s1.top();
        s1.pop();
        int tmp2 = 0;
        while (s2.size())
        {
            tmp2 = s2.top();
            s2.pop();
            s1.push(tmp2);
        }
        return tmp;
    }

    int peek() {
        int tmp = 0;
        while (s1.size())
        {
            tmp = s1.top();
            s1.pop();
            s2.push(tmp);
        }
        int tmp2 = 0;
        while (s2.size())
        {
            tmp2 = s2.top();
            s2.pop();
            s1.push(tmp2);
        }
        return tmp;
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main()
{
    MyQueue my;
    my.push(1);
    my.push(2);
    my.push(3);
    my.push(4);
    my.pop();
    my.push(5);
    my.pop();
    my.pop();
    my.pop();
    return 0;
}