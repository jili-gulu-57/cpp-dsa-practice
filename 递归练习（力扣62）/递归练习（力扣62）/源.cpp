#include<iostream>
using namespace std;

//62.不同路径（已通过）
class Solution {
    int memo[100][100] = { 0 };
public:
    int uniquePaths(int m, int n) {
        return dfs(m - 1, n - 1);
    }
    int dfs(int x, int y)
    {
        if (memo[x][y])
            return memo[x][y];
        if (x < 0 || y < 0) return 0;

        if (x == 0 && y == 0)
        {
            memo[x][y] = 1;
            return 1;
        }

        memo[x][y] = dfs(x - 1, y) + dfs(x, y - 1);

        return memo[x][y];
    }
};

int main()
{
    Solution s;
    s.uniquePaths(3, 2);
    return 0;
}