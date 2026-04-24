#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//93.复原IP地址（已通过）
class Solution {
    vector<string> ans;
    string path;
    int _n;
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        if (n < 4 || n>12)
            return ans;

        _n = n;
        dfs(s,0);
        return ans;
    }
    void dfs(string& s, int pos)
    {
        if (count(path.begin(), path.end(), '.') == 3)
        {
            //检查最后一段是否合法
            string last = s.substr(pos);
            if(Is_valid(last))
            ans.push_back(path+last);
            return;
        }

        for (int i = 1; i <= 3; i++)
        {
            if (pos + i > _n)
                break;

            string sub = s.substr(pos, i);
            if (Is_valid(sub))
            {
                int originalSize = path.size();
                path += sub;
                path += '.';
                dfs(s, pos + i);
                path.resize(originalSize);//通过调整有效长度来回溯
            }
        }
    }
    bool Is_valid(const string& sub)
    {
        int n = sub.size(), num = 0;

        if (n == 0)
            return false;

        //有前导0为错误情况
        if (sub[0] == '0' && n > 1)
            return false;

        for (int i = 0; i < n; i++)
        {
            num *= 10;
            num += sub[i] - '0';
        }
        //cout << num << endl;
        //判断数字是否合法
        if (num >= 0 && num <= 255)
            return true;
        return false;
    }
};

void PrintAns(vector<string>& ans)
{
    for (auto c : ans)
        cout << c << " ";
    cout << endl;
}

int main()
{
    Solution s;
    vector<string> ans;
    ans=s.restoreIpAddresses("101023");
    PrintAns(ans);
    return 0;
}