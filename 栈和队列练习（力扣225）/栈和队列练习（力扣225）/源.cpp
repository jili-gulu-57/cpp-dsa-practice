#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<queue>
using namespace std;

//已通过
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }

    void push(int x) {
        //都为空时往q1里插入数据
        if (q1.empty() && q2.empty())
            q1.push(x);
        else if (q1.empty())//q1为空，往q2里插入数据
            q2.push(x);
        else
            q1.push(x);
    }

    int pop() {
        //q1为空往q1放数据
        if (q1.empty())
        {
            while (q2.size() != 1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            int tmp = q2.front();
            q2.pop();
            return tmp;
        }
        else//q2为空，往q2里放数据
        {
            while (q1.size()!=1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            int tmp = q1.front();
            q1.pop();
            return tmp;
        }
    }

    int top() {
        //q1为空说明数据都在q2里
        if (q1.empty())
            return q2.back();
        else
            return q1.back();
    }

    bool empty() {
        return q1.empty() && q2.empty();
    }
};
int main()
{
    MyStack M;
    return 0;
}