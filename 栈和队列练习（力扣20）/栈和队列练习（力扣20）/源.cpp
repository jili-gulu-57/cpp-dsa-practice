#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<stack>
using namespace std;

//ÒÑÍ¨¹ý
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ')')
            {
                if (st.empty())
                    return false;
                else
                {
                    char tmp = st.top();
                    st.pop();
                    if (tmp != '(')
                        return false;
                }
            }
            else if (s[i] == '}')
            {
                if (st.empty())
                    return false;
                else
                {
                    char tmp = st.top();
                    st.pop();
                    if (tmp != '{')
                        return false;
                }
            }
            else if (s[i] == ']')
            {
                if (st.empty())
                    return false;
                else
                {
                    char tmp = st.top();
                    st.pop();
                    if (tmp != '[')
                        return false;
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
        if (st.empty())
            return true;
        else
            return false;
    }
};