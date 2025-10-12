#include<iostream>
#include<vector>
using namespace std;


//1219.黄金矿工（已通过）
class Solution {
    bool vis[16][16];
    int dx[4] = { 1,-1,0,0 };
    int dy[4] = { 0,0,1,-1 };
    int m, n;
    int ans;
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    vis[i][j] = true;
                    dfs(grid, i, j, grid[i][j]);
                    vis[i][j] = false;
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& grid, int i, int j, int path)
    {
        ans = max(ans, path);
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && grid[x][y])
            {
                vis[x][y] = true;
                dfs(grid, x, y, path+ grid[x][y]);
                vis[x][y] = false;
            }
        }
    }
};

int main()
{
    vector<vector<int>> grid = { {0,6,0},{5,8,7},{0,9,0} };
    Solution s;
    s.getMaximumGold(grid);
    return 0;
}