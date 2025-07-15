#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<stack>
using namespace std;


//227.基本计算器Ⅱ（已通过）
//表达式求值，基本思路都是用栈模拟
class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        char op = '+';
        int num = 0;
        for (int i=0;i<s.size();i++)
        {
            if (s[i] == ' ')
                continue;
            if (s[i] >= '0' && s[i] <= '9')
            {
                while (s[i] >= '0' && s[i] <= '9')
                {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                if (op == '+')
                    st.push(num);
                else if (op == '-')
                    st.push(-num);
                else if (op == '*')
                {
                    int tmp = st.top();
                    st.pop();
                    tmp *= num;
                    st.push(tmp);
                    op = '+';
                }
                else if (op == '/')
                {
                    int tmp = st.top();
                    st.pop();
                    tmp /= num;
                    st.push(tmp);
                    op = '+';
                }
            }
            else
            {
                num = 0;
                op = s[i];
            }
        }
        int ans = 0;
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};

int main()
{
    string s = " 3/2 ";
    Solution ss;
    ss.calculate(s);
    return 0;
}