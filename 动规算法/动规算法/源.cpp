#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>
#include<iostream>
using namespace std;


//918.环形子数组的最大和（已通过）
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans = 0, n = nums.size(), sum = nums[0];
        if (n == 1)
            return nums[0];
        vector<int> f(n);//找最大子数组和
        vector<int> g(n);//找最小子数组和
        f[0] = nums[0];
        g[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            f[i] = max(nums[i], nums[i] + f[i - 1]);
            g[i] = min(nums[i], nums[i] + g[i - 1]);
            sum += nums[i];
        }
        int m1 = INT_MIN, m2 = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            m1 = max(m1, f[i]);
            m2 = min(m2, g[i]);
        }
        sum -= m2;
        //可能出现数组全是负数，此时sum=0，但这种情况错误，需要特别判断
        //不会出现sum=0，结果仍是sum的情况，因为sum=0，要么数组全负，要么数组除负数有零，此时m1的值也是0
        //因此不必担心sum=0的两种情况影响最终结果
        return sum == 0 ? m1 : max(m1, sum);
    }
};