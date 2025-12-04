#include<iostream>
#include<vector>
#include<queue>
using namespace std;


//215.数组中的第k个最大元素（已通过）
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap;   //默认是大堆

        //建堆
        for (auto x : nums)
            heap.push(x);

        //出堆
        k--;
        while (k--)
            heap.pop();

        return heap.top();
    }
};

int main()
{
    int a = 1;
    char* p = (char*)a;
    cout << *p;
    return 0;
}