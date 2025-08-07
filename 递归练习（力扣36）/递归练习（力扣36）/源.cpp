#include<iostream>
#include<vector>
using namespace std;


//36.有效的数独（已通过）
class Solution {
public:
    bool row[9][10];
    bool col[9][10];
    bool grid[3][3][10];
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
        {
            int index = 1;
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                int y = board[i][j] - '0';
                if (row[i][y] == true)
                    return false;
                if (col[j][y] == true)
                    return false;
                if (grid[i / 3][j / 3][y] == true)
                    return false;
                row[i][y] = true;
                col[j][y] = true;
                grid[i / 3][j / 3][y] = true;
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<char>> board = { {'.','.','4','.','.','.','6','3','.'},{'.','.','.','.','.','.','.','.','.'},{'5','.','.','.','.','.','.','9','.'},
    {'.','.','.','5','6','.','.','.','.'},{'4','.','3','.','.','.','.','.','1'},{'.','.','.','7','.','.','.','.','.'},
        {'.','.','.','5','.','.','.','.','.'},{'.','.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.','.'} };
    Solution s;
    s.isValidSudoku(board);
    return 0;
}