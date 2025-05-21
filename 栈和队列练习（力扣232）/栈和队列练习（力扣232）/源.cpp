#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stack>
using namespace std;

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
        while (s2.size())
        {
            tmp = s2.top();
            s2.pop();
            s1.push(tmp);
        }
        return tmp;
    }

    int peek() {
        return s1.top();
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