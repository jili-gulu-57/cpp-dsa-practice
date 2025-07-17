#include<iostream>
#include<string>
#include<vector>
using namespace std;


//43.字符串相乘（已通过）
//模拟竖式运算优化版
//采用无进位相乘再相加，最后处理进位
class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size(), m = num2.size();

        //元素个数为m+n-1，初始值为0
        vector<int> sum(m + n, 0);
        string ans;
        //无进位相乘，相加
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                sum[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        //处理进位
        int x = 0;//进位结果
        for (int i = m + n - 1; i >= 1; i--)
        {
            sum[i] = x + sum[i - 1];
            x = sum[i] / 10;
            sum[i] = sum[i] % 10;
        }
        sum[0] = x;
        //转换成string类型
        for (auto x : sum)
            ans.push_back(x + '0');
        //处理前导零和全是零的情况
        while (ans.front() == '0' && ans.size() > 1)
            ans = ans.substr(1);
        return ans;
    }
};

int main()
{
    string num1 = { 2 };
    string num2 = { 3 };
    Solution s;
    s.multiply(num1, num2);
    return 0;
}