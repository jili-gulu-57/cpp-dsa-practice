#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//53.最大子数组和（已通过）
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];

        //填表
        for (int i = 1; i < n; i++)
        {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
        }

        int ans = -INT_MAX;//数据包含负数
        for (auto x : dp)
            ans = max(ans, x);
        return ans;
    }
};