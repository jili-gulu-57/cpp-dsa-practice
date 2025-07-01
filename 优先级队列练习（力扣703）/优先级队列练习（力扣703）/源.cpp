#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//优先级队列：类似于常规队列，但是不是FIFO顺序出数据，而是根据优先级
//优先级最高的先出，优先级相同的一般按插入顺序出

//703.数据流中的第k大元素（已通过）
class KthLargest {
    //优先级队列默认是大根堆，自定义小根堆要使用std::greater<> 作为比较器，还要指定底层容器
    priority_queue<int, vector<int>, greater<int>> heap;
    int _k;
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for (auto ch : nums)
        {
            heap.push(ch);
            if (heap.size() > k)
                heap.pop();
        }
    }

    int add(int val) {
        heap.push(val);
        if (heap.size() > _k)
            heap.pop();
        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main()
{
    vector<int> nums = { 4,5,8,2 };
    KthLargest(3, nums);
    return 0;
}