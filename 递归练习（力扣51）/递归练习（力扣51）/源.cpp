#include<iostream>
#include<vector>
using namespace std;


//51.N皇后（已通过）
class Solution {
public:
    int _n;
    //用来判断这一竖列，主对角线，副对角线是否有皇后
    bool checkCol[10], checkDig1[20], checkDig2[20];
    vector<vector<string>> ans;
    vector<string> path;

    vector<vector<string>> solveNQueens(int n) {
        _n = n;
        path.resize(n);
        for (int i = 0; i < n; i++)
            path[i].append(_n, '.');
        dfs(0);
        return ans;
    }
    void dfs(int row)
    {
        if (row == _n)
        {
            ans.push_back(path);
            return;
        }
        //固定一行，看哪一列可以放皇后
        for (int i = 0; i < _n; i++)
        {
            if (!checkCol[i] && !checkDig1[row - i + _n] && !checkDig2[i + row])
            {
                path[row][i] = 'Q';
                checkCol[i] = checkDig1[row - i + _n] = checkDig2[i + row] = true;
                dfs(row + 1);
                //恢复现场
                path[row][i] = '.';
                checkCol[i] = checkDig1[row - i + _n] = checkDig2[i + row] = false;
            }
        }
    }
};

int main()
{
    Solution s;
    s.solveNQueens(4);
    return 0;
}