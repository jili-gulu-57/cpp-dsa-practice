#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//已通过
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;//默认为大根堆

        //入堆
        for (auto x : stones)
            heap.push(x);

        int x = 0, y = 0;
        while (heap.size() > 1)
        {
            x = heap.top();
            heap.pop();
            y = heap.top();
            heap.pop();
            if (x - y)
                heap.push((x - y));
        }
        if (heap.size())
            return heap.top();
        return 0;
    }
};
