#include<iostream>
#include<vector>
using namespace std;

//LCR 130.衣橱整理（已通过）
class Solution {
    int dx[2] = { 0,1 };
    int dy[2] = { 1,0 };
    int ans = 0;
    int gm, gn, gcnt;
public:
    int wardrobeFinishing(int m, int n, int cnt) {
        vector<vector<char>> grid(m, vector<char>(n,'0'));
        gm = m;
        gn = n;
        gcnt = cnt;
        dfs(grid,0,0);
        cout << ans;
        return ans;
    }
    void dfs(vector<vector<char>>& grid,int a,int b)
    {
        //计算数位和是否大于cnt
        int count = (a % 10) + (a / 10) + (b % 10) + (b / 10);
        if (count > gcnt)
            return;
        ans++;
        grid[a][b] = '1';
        for (int i = 0; i < 2; i++)
        {
            int x = a + dx[i], y = b + dy[i];
            if (x >= 0 && x < gm && y >= 0 && y < gn && grid[x][y]=='0')
            {
                dfs(grid, x, y);
            }
        }
    }
};

int main()
{
    Solution s;
    s.wardrobeFinishing(4, 5, 4);
    return 0;
}