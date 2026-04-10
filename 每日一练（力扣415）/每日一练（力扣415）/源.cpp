#include<iostream>
#include<vector>
#include<string>
using namespace std;

//415.字符串相加（已通过）
class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        int size = max(m, n) + 1;
        string ans(size,'0');
        int index = size - 1;
        m--;
        n--;
        int x = 0, y = 0;
        while (m >= 0 && n >= 0)
        {
            x = ((num1[m] - '0') + (num2[n] - '0')) % 10; //余数
            if (x + y == 10)
            {
                ans[index--] = '0';
                y = ((num1[m] - '0') + (num2[n] - '0')) / 10 + 1;
            }
            else
            {
                ans[index--] = x + '0' + y;
                y = ((num1[m] - '0') + (num2[n] - '0')) / 10;
            }
            m--;
            n--;
        }
        while (m >= 0)
        {
            x = num1[m--] - '0' + y;
            if (x == 10)
            {
                ans[index--] = '0';
                y = 1;
            }
            else
            {
                ans[index--] = x + '0';
                y = 0;
            }
        }
        while (n >= 0)
        {
            x = num2[n--] - '0' + y;
            if (x == 10)
            {
                ans[index--] = '0';
                y = 1;
            }
            else
            {
                ans[index--] = x + '0';
                y = 0;
            }
        }
        if (y == 1)
            ans[0] = '1';
        if (ans[0] == '0')
            ans = ans.substr(1);
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.addStrings("456", "77");
    return 0;
}