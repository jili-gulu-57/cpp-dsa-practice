#include<iostream>
#include<vector>
#include<queue>
using namespace std;


//542.01矩阵（已通过）
class Solution {
public:
    int dx[4] = { 1,-1,0,0 };
    int dy[4] = { 0,0,1,-1 };
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        //等于-1表示这格未被搜索过
        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        //将所有0点加入队列和数组
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    ans[i][j] = 0;
                    q.push({ i,j });
                }
            }
        }
        int dis = 1;
        while (q.size())
        {
            auto [a, b] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int x = a + dx[i], y = b + dy[i];
                if (x >= 0 && x < n && y >= 0 && y < m && ans[x][y] == -1)
                {
                    ans[x][y] = ans[a][b] + 1;
                    q.push({ x,y });
                }
                
            }
        }
        return ans;
    }
};