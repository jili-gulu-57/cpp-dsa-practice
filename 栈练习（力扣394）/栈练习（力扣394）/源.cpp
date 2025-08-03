#include<iostream>
#include<stack>
#include<string>
using namespace std;


//394.字符串解码（已通过）
class Solution {
public:
    string decodeString(string s) {
        stack<int> s1;
        stack<string> s2;
        s2.push("");
        int n = s.size();
        for (int i = 0; i < n;)
        {
            int tmp = 0;
            while (isdigit(s[i]))
            {
                tmp = tmp * 10 + (s[i] - '0');
                i++;
            }
            if (tmp)
                s1.push(tmp);
            if (s[i] == '[')
            {
                i++;
                string a;
                while (isalpha(s[i]))
                    a.push_back(s[i++]);
                s2.push(a);
            }
            string b;
            while (isalpha(s[i]))
                b.push_back(s[i++]);
            if (b.size())
            {
                string c = s2.top();
                s2.pop();
                c += b;
                s2.push(c);
            }
            if (s[i] == ']')
            {
                int d = s1.top();
                s1.pop();
                string e = s2.top();
                s2.pop();
                string f = s2.top();
                s2.pop();
                while (d--)
                    f += e;
                s2.push(f); 
                i++;
            }
        }
        return s2.top();
    }
};

int main()
{
    string ss = "abc3[cd]xyz";
    Solution s;
    cout<<s.decodeString(ss);
    return 0;
}