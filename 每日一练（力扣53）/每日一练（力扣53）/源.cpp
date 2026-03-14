#include<iostream>
#include<vector>
using namespace std;

//53.最大子数组和（已通过）
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], n = nums.size();
        int l = 0, r = l + 1;

        //找到前缀和
        vector<int> sum(n);
        sum[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            sum[i] = sum[i - 1] + nums[i];
        }

        int dif = 0;
        while (r < n)
        {
            if (l == 0)
            {
                dif = sum[r];
            }
            else
            {
                dif = sum[r] - sum[l - 1];
            }
            ans = max(ans, dif);

            if (nums[r] >= ans)
            {
                l = r;
                ans = nums[r];
            }

            if (nums[r] >= 0 && nums[r] >= dif)
            {
                l = r;
            }
            r++;
        }

        return ans;
    }
};

//动规答案
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

//（未通过）
//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        int ans1 = nums[0], n = nums.size();
//        int ans2 = nums[n - 1], ans = 0;
//
//        //找到前缀和
//        vector<int> sum(n);
//        sum[0] = nums[0];
//        for (int i = 1; i < n; i++)
//        {
//            sum[i] = sum[i - 1] + nums[i];
//        }
//
//        int l = 0, r = l + 1;
//        while (r < n)
//        {
//            if (l==0)
//            {
//                ans1 = max(ans1, sum[r]);
//            }
//            else
//            {
//                ans1 = max(ans1, sum[r] - sum[l - 1]);
//            }
//
//            if (nums[r] >= ans1)
//            {
//                l = r;
//                ans1 = nums[r];
//            }
//            r++;
//        }
//
//        r = n - 1;
//        l = r - 1;
//        while (l >= 0)
//        {
//            if (l == 0)
//            {
//                ans2 = max(ans2, sum[r]);
//            }
//            else
//            {
//                ans2 = max(ans2, sum[r] - sum[l - 1]);
//            }
//
//            if (nums[l] >= ans2)
//            {
//                r = l;
//                ans2 = nums[l];
//            }
//            l--;
//        }
//
//        ans = max(ans1, ans2);
//        return ans;
//    }
//};