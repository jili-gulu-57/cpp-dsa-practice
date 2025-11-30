#include<iostream>
#include<vector>
using namespace std;


//417.太平洋大西洋水流问题
class Solution {
    int m, n;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        vector<vector<bool>> p(m, vector<bool>(n));
        vector<vector<bool>> a(m, vector<bool>(n));
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


    }

    void dfs(vector<vector<int>>& heights, int begin, int end, vector<vector<bool>>& oc)
    {

    }
};