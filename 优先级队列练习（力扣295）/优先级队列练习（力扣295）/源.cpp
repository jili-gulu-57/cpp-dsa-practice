#include<iostream>
#include<queue>
#include<vector>
using namespace std;


//295.数据流的中位数（已通过）
class MedianFinder {

    priority_queue<int> left;   //C++默认大根堆
    priority_queue<int, vector<int>, greater<int>> right;   //小根堆

public:
    MedianFinder()
    {}

    void addNum(int num) 
    {
        int m = left.size(), n = right.size();
        if (m == n)
        {
            if (m == 0 || num <= left.top())
                left.push(num);
            else
            {
                right.push(num);
                left.push(right.top());
                right.pop();
            }
        }
        else
        {
            if (num <= left.top())
            {
                left.push(num);
                right.push(left.top());
                left.pop();
            }
            else
                right.push(num);
        }
          }

    double findMedian() {
        int m = left.size(), n = right.size();
        if (m == n)
            return (left.top() + right.top()) / 2.0;
        else
            return left.top();
    }
};

int main()
{

    MedianFinder m;
    m.addNum(1);    // arr = [1]
    m.findMedian(); // 返回 1.5 ((1 + 2) / 2)
    return 0;
}