#include<iostream>
#include<string>
#include<stack>
using namespace std;

//20.有效的括号（已通过）
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto c : s)
        {
            if (c == '(' || c == '{' || c == '[')
                st.push(c);
            else
            {
                //符合是右括号且s为空
                if (st.empty())
                    return false;
                if (c == ')' && st.top() != '(')
                    return false;
                if (c == '}' && st.top() != '{')
                    return false;
                if (c == ']' && st.top() != '[')
                    return false;

                st.pop();
            }
        }
        if (st.empty())
            return true;

        return false;
    }
};

int main()
{
    string s = "({[]";
    Solution ss;
    ss.isValid(s);
    return 0;
}