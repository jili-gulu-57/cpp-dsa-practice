#include<iostream>
#include<vector>
using namespace std;

//1567.乘积为正数的最长子数组长度（已通过）
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 1);   //记录乘积为正数
        vector<int> g(n + 1);   //记录乘积为负数
        f[0] = g[0] = 0;
        int ans = 0;
        for (size_t i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                f[i + 1] = f[i] + 1;
                g[i + 1] = g[i] == 0 ? 0 : g[i] + 1;
            }
            else if (nums[i] < 0)
            {
                g[i + 1] = f[i] + 1;
                f[i + 1] = g[i] == 0 ? 0 : g[i] + 1;
            }
            else
            {
                f[i] = 0;
                g[i] = 0;
            }
            ans = max(ans, f[i + 1]);
        }
        return ans;
    }
};