#include<iostream>
#include<vector>
using namespace std;

//79.单词搜索（已通过）
class Solution {
    bool vis[7][7];
    int m, n;
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    vis[i][j] = true;
                    if (dfs(board, i, j, 1, word))
                        return true;
                    vis[i][j] = false;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, int x, int y, int pos, string& word)
    {
        if (pos == word.size())
            return true;

        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < m && b >= 0 && b < n && !vis[a][b] && board[a][b] == word[pos])
            {
                vis[a][b] = true;
                if (dfs(board, a, b, pos + 1, word))
                    return true;
                vis[a][b] = false;
            }
        }
        return false;
    }
};