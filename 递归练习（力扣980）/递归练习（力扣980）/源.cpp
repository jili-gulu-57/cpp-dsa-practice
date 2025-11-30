#include<iostream>
#include<vector>
using namespace std;

//980.不同路径Ⅲ（已通过）
//暴力枚举，找出所有路线，但当step==count时，加入最终结果
class Solution {
public:
    bool vis[20][20] = { 0 };
    int dx[4] = { 1,-1,0,0 };
    int dy[4] = { 0,0,1,-1 };
    int ans = 0;
    int bx = 0, by = 0, m = 0, n = 0, step = 0;
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        //找出起点位置坐标和全走完需要的步数
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                    step++;
                if (grid[i][j] == 1)
                {
                    bx = i;
                    by = j;
                    //搜索过程可能会回到1的位置
                    vis[i][j] = true;
                }
            }
        }
        step ++;

        dfs(grid, bx, by,0);
        return ans;
    }
    void dfs(vector<vector<int>>& grid, int a, int b, int count)
    {
        //判断出口条件
        if (grid[a][b] == 2)
            if (count == step)
                ans++;

        for (int k = 0; k < 4; k++)
        {
            int x = dx[k] + a;
            int y = dy[k] + b;
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != -1 && !vis[x][y])
            {
                vis[x][y] = true;
                dfs(grid, x, y, count+1);//如果在外面进行count++，则count不能正确回退
                vis[x][y] = false;
            }
        }
    }
};

int main()
{
    vector<vector<int>> grid = { {0,1},{2,0} };
    Solution s;
    s.uniquePathsIII(grid);
    return 0;
}