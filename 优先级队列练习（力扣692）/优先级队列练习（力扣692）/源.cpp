#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

//692.前K个高频单词（已通过）
class Solution {
    //经常用到，起个别名方便后续操作
    typedef pair<string, int> PSI;

    struct cmp  //cmp==true，表示a的优先级低于b的优先级
    {
        bool operator()(const PSI& a, const PSI& b)
        {
            if (a.second == b.second)//频次相同
            {
                //返回true时，表示a的字典序小于b的字典序，a优先级低，被放在后面，出堆时将字典序在前面的出堆。
                return a.first < b.first;
                
            }

            //频率不同时，返回true表示a的频次大于b的频次，a的优先级低
            //a会被放在堆的后面，进行出队操作，会将前面的，即频次少的出堆。
            else
                return a.second > b.second;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hash;
        for (auto& w : words)
            hash[w]++;

        //C++默认创建的是大根堆，其构造函数为  priority_queue<int> pq;
      
        //创建的是小根堆，需要显示写出底层容器和比较函数
        priority_queue<PSI, vector<PSI>, cmp> pq;

        for (auto& psi : hash)
        {
            pq.push(psi);
            if (pq.size() > k)
                pq.pop();
        }

        vector<string> ans(k);

        //因为创建的是小根堆，物理结构上频次最大的在后面，所以要进行逆序
        //数组中直接从后往前放，替代逆序操作
        for (int i = k - 1; i >= 0; i--)
        {
            ans[i] = pq.top().first;
            pq.pop();
        }
        return ans;
    }
};