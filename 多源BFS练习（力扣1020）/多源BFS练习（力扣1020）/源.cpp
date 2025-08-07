#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//1020.飞地的数量（已通过）
//正难则反，从边界开始搜索，将可以遍历到的1加入
class Solution {
public:
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            if (grid[i][0] == 1)
            {
                q.push({ i,0 });
                vis[i][0] = true;
            }
            if (grid[i][n - 1] == 1)
            {
                q.push({ i,n - 1 }); 
                vis[i][n - 1] = true;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (grid[0][i] == 1)
            {
                q.push({ 0,i });
                vis[0][i] = true;
            }
            if (grid[m - 1][i] == 1)
            {
                q.push({ m - 1,i });
                vis[m - 1][i] = true;
            }
        }
        while (q.size())
        {
            auto [a, b] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int x = a + dx[i];
                int y = b + dy[i];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 && !vis[x][y])
                {
                    vis[x][y] = true;
                    q.push({ x,y });
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1 && !vis[i][j])
                    ans++;
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> grid = { {0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0} };
    Solution s;
    cout<<s.numEnclaves(grid);
    return 0;
}