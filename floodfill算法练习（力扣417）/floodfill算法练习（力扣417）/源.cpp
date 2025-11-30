#include<iostream>
#include<vector>
using namespace std;


//417.太平洋大西洋水流问题（已通过）
class Solution {
    int m, n;
    int dx[4] = { 1,-1,0,0 };
    int dy[4] = { 0,0,1,-1 };
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        vector<vector<bool>> p(m, vector<bool>(n,0));
        vector<vector<bool>> a(m, vector<bool>(n,0));
        vector<vector<int>> ans;

        //统计第一个洋
        for (int i = 0; i < n; i++)
            dfs(heights, 0, i, p);
        for (int i = 0; i < m; i++)
            dfs(heights, i, 0, p);
        //统计第二个洋
        for (int i = 0; i < m; i++)
            dfs(heights, i, n - 1, a);
        for (int i = 0; i < n; i++)
            dfs(heights, m - 1, i, a);

        //找出最终结果
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (p[i][j] && a[i][j])
                    ans.push_back({ i,j });
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& oc)
    {
        oc[i][j] = true;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && heights[x][y] >= heights[i][j] && !oc[x][y])
            {
                oc[x][y] = true;
                dfs(heights, x, y, oc);
            }
        }
    }
};