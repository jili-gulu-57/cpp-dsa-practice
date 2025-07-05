#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//有多个源点同时向外扩展
//1765.地图中的最高点（已通过）
class Solution {
public:
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        //将所有源点加入到队列里面
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isWater[i][j])
                {
                    ans[i][j]=0;
                    q.push({ i,j });
                }
            }
        }

        //多源bfs
        while (q.size())
        {
            auto [a, b] = q.front();//C++17标准
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int x = a + dx[i], y = b + dy[i];
                if (x >= 0 && x < m && y>=0 && y < n && ans[x][y] == -1)
                {
                    ans[x][y] = ans[a][b] + 1;
                    q.push({ x,y });
                }
            }
        }
        return ans;
    }
};