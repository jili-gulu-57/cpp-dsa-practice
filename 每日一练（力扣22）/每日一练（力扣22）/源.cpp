#include<iostream>
#include<vector>
#include<string>
using namespace std;

//22.括号生成（已通过）
class Solution {
    vector<string> ans;
    string path;
    int left, right;
public:
    vector<string> generateParenthesis(int n) {
        left = 0, right = 0;
        dfs(n);
        return ans;
    }
    void dfs(int n)
    {
        if (path.size() == 2 * n)
        {
            ans.push_back(path);
            return;
        }
        if (left < n)
        {
            path += "(";
            left++;
            dfs(n);
            path.pop_back();
            left--;
        }
        if (right < left)
        {
            path += ")";
            right++;
            dfs(n);
            path.pop_back();
            right--;
        }
    }
};

int main()
{
    Solution s;
    s.generateParenthesis(3);
    return 0;
}