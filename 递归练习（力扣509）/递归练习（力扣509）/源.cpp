#include<iostream>
#include<vector>
using namespace std;

//509.斐波那契数（已通过）
class Solution {
public:
    int fib(int n) {
        vector<int> memo(n + 1,-1 );
        return dfs(n,memo);
    }
    int dfs(int n, vector<int>& memo)
    {
        if (memo[n] != -1)
            return memo[n];

        if (n == 0 || n == 1)
        {
            memo[n] = n;
            return n;
        }

        memo[n] = dfs(n - 1, memo) + dfs(n - 2, memo);
        return memo[n];
    }
};

int main()
{
    Solution s;
    s.fib(2);
    return 0;
}