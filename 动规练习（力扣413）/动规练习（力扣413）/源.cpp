#include<iostream>
#include<vector>
using namespace std;


//413.等差数组划分（已通过）
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        if (n < 3)
            return 0;
        vector<int> dp(n);
        dp[0] = dp[1] = 0;
        for (int i = 1; i < n - 1; i++)
        {
            int c = nums[i + 1], b = nums[i], a = nums[i - 1];
            if ((c - b) == (b - a))
                dp[i + 1] = dp[i] + 1;
            else
                dp[i + 1] = 0;
            ans += dp[i + 1];
        }
        return ans;
    }
};