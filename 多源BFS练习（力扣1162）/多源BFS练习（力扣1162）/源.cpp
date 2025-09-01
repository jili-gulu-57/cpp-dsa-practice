#include<iostream>
#include<vector>
#include<queue>
using namespace std;


//1162.地图分析（已通过）
class Solution {
    int dx[4] = { 1,-1,0,0 };
    int dy[4] = { 0,0,1,-1 };
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({ i,j });
                    dist[i][j] = 0;
                }
            }
        }

        int ret = -1;

        while (q.size())
        {
            auto [a, b] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int x = a + dx[i];
                int y = b + dy[i];
                if (x >= 0 && x < m && y >= 0 && y < n && dist[x][y] == -1)
                {
                    dist[x][y] = dist[a][b] + 1;
                    q.push({ x,y });
                    ret = max(ret, dist[x][y]);
                }
            }

        }
        return ret;
    }
};

int main()
{
    vector<vector<int>> grid = { {1,0,1},{0,0,0},{1,0,1} };
    Solution s;
    s.maxDistance(grid);
    return 0;
}