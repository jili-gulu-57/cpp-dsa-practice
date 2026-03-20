#include<iostream>
#include<vector>
using namespace std;

//200.岛屿数量（已通过）
class Solution {
    int dx[4] = { 1,-1,0,0 };
    int dy[4] = { 0,0,1,-1 };
    int ans = 0;
    bool vis[300][300] = { 0 };
    int m, n;
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        for (int a = 0; a < m; a++)
        {
            for (int b = 0; b < n; b++)
            {
                if (grid[a][b] == '1' && !vis[a][b])
                {
                    dfs(grid, a, b);
                    ans++;
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& grid,int a,int b)
    {
        if (grid[a][b] == '0')
            return;
        
        if (grid[a][b] == '1' && !vis[a][b])
        {
            vis[a][b] = true;
            for (int i = 0; i < 4; i++)
            {
                int x = a + dx[i], y = b + dy[i];
                if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y])
                {
                    dfs(grid, x, y);
                }
            }
        }
    }
};

int main()
{
    Solution s;
    vector<vector<char>> grid = { {'1','1','0','0','0'},{'1','1','0','0','0'},
        {'0','0','1','0','0'},{'0','0','0','1','1'} };
    cout<<s.numIslands(grid);
    return 0;
}