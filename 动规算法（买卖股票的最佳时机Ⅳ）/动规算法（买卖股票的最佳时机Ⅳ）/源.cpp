#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//已通过
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        const int INF = 0x3f3f3f3f;
        int n = prices.size();
        //优化k，因为最多只能交易n/2次
        k = min(k, n / 2);

        //创建dp表
        vector<vector<int>> f(n, vector<int>(k + 1, -INF));
        vector<vector<int>> g(n, vector<int>(k + 1, -INF));
        f[0][0] = -prices[0];
        g[0][0] = 0;

        //填表
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                f[i][j] = max(f[i - 1][j], g[i - 1][j] - prices[i]);
                g[i][j] = g[i - 1][j];
                if (j > 0)
                {
                    g[i][j] = max(g[i][j], f[i - 1][j - 1] + prices[i]);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= k; i++)
            ans = max(ans, g[n - 1][i]);
        return ans;
    }
};