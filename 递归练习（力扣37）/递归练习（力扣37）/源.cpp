#include<iostream>
#include<vector>
using namespace std;


//37.解数独（已通过）
class Solution {
    bool row[10][10];   //行
    bool col[10][10];   //列
    bool map[3][3][10]; //九宫格
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if(board[i][j]!='.')
                {
                    int x = board[i][j] - '0';
                    row[i][x] = true;
                    col[j][x] = true;
                    map[i / 3][j / 3][x] = true;
                }
            }
        }
        dfs(board);
        return;
    }
    bool dfs(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    for (int n = 1; n <= 9; n++)    //开始填数，从1到9
                    {
                        if (!row[i][n] && !col[j][n] && !map[i / 3][j / 3][n])
                        {
                            board[i][j] = n + '0';  //数组是char类型

                            //填完数注意要再次标记
                            row[i][n] = col[j][n] = map[i / 3][j / 3][n] = true;

                            if (dfs(board))
                                return true;

                            //恢复现场
                            board[i][j] = '.';
                            //恢复现场后，将标记改回来
                            row[i][n] = col[j][n] = map[i / 3][j / 3][n] = false;
                        }
                    }
                    return false;   //说明所有数都不对
                }
            }
        }
        return true;
    }
};