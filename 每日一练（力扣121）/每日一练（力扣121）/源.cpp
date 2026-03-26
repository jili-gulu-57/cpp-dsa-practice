#include<iostream>
#include<vector>
using namespace std;

//121.买卖股票的最佳时机（已通过）
//动规算法
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), ans = 0;
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = -prices[0];  //持有股票
        dp[0][1] = 0;           //不持有股票
        for (int i = 1; i < n; i++)
        {
            //因为只能购买一次，所以不能是dp[i-1][1] - prices[i]
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            ans = max(ans, dp[i][0]);
            ans = max(ans, dp[i][1]);
        }
        return ans;
    }
};