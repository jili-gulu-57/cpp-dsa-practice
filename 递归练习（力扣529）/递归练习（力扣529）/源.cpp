#include<iostream>
#include<vector>
using namespace std;


//棋盘打印
void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
}

//529.扫雷游戏（已通过）
class Solution {
    int dx[8] = { 1,-1,0,0,1,1,-1,-1 };
    int dy[8] = { 0,0,1,-1,1,-1,1,-1 };
    int m, n;
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size();
        n = board[0].size();

        //判断是否直接踩到雷
        if (board[click[0]][click[1]] == 'M')
        {
            board[click[0]][click[1]] = 'X';
            return board;
        }

        dfs(board, click[0], click[1]);
        return board;
    }
    void dfs(vector<vector<char>>&board, int i, int j)
    {
        //统计九宫格雷的个数
        int count = 0;
        for (int k = 0; k < 8; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y]=='M')
            {
                count++;
            }
        }

        //有雷修改棋盘,不递归
        if(count)
        {
            board[i][j] = count + '0';
            return;
        }
        //无雷情况继续递归
        else
        {
            board[i][j] = 'B';
            for (int k = 0; k < 8; k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'E')
                {
                    dfs(board, x, y);
                }
            }
        }
    }
};


int main()
{
    vector<vector<char>> board = {
    {'E', 'E', 'E', 'E', 'E'},
    {'E', 'E', 'M', 'E', 'E'},
    {'E', 'E', 'E', 'E', 'E'},
    {'E', 'E', 'E', 'E', 'E'}
    };
    vector<int> click = { 3,0 };
    Solution s;
    s.updateBoard(board, click);
    return 0;
}