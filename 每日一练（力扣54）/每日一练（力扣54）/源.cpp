#include<iostream>
#include<vector>
using namespace std;

//54.螺旋矩阵（已通过）
//模拟：使用单独变量标记遍历时不变的边界
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        vector<int> ans;
        int count = m * n, num = 1, i1 = 0, j1 = 0, i2 = m - 1, j2 = n - 1;
        while(count)
        {
            if(num % 4 == 1)
            {
                for (int j = 0; j < n; j++)
                {
                    if (!vis[i1][j])
                    {
                        ans.push_back(matrix[i1][j]);
                        vis[i1][j] = true;
                        count--;
                    }
                }
                i1++;
            }
            else if(num % 4 == 2)
            {
                for (int i = 0; i < m; i++)
                {
                    if (!vis[i][j2])
                    {
                        ans.push_back(matrix[i][j2]);
                        vis[i][j2] = true;
                        count--;
                    }
                }
                j2--;
            }
            else if (num % 4 == 3)
            {
                for (int j = n - 1; j >= 0; j--)
                {
                    if (!vis[i2][j])
                    {
                        ans.push_back(matrix[i2][j]);
                        vis[i2][j] = true;
                        count--;
                    }
                }
                i2--;
            }
            else
            {
                for (int i = m - 1; i >= 0; i--)
                {
                    if (!vis[i][j1])
                    {
                        ans.push_back(matrix[i][j1]);
                        vis[i][j1] = true;
                        count--;
                    }
                }
                j1++;
            }
            num++;
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> m = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{17,18,19,20},{21,22,23,24} };
    Solution s;
    s.spiralOrder(m);
    return 0;
}