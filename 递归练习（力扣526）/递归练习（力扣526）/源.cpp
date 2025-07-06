#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//526.优美的排列（已通过）
class Solution {
public:
    bool check[16];
    int ans;

    int countArrangement(int n) {
        dfs(1, n);
        return ans;
    }
    void dfs(int pos, int n)
    {
        if (pos == n + 1)
        {
            ans++;
            return;
        }
        for (int i = 1; i <= n; i++)
        {
            if (!check[i] && (i % pos == 0 || pos % i == 0))
            {
                check[i] = true;
                dfs(pos + 1, n);
                check[i] = false;
            }
        }
    }
};