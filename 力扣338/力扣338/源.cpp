#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//338.比特位计数（已通过）
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; i++)
        {
            int tmp = i,count = 0;
            while (tmp)
            {
                if ((tmp & 1) == 1)
                    count++;
                tmp = tmp >> 1;
            }
            ans[i] = count;
        }
        return ans;
    }
};