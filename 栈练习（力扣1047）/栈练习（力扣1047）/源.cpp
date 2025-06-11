#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//用string模拟栈（已通过）
class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        for (int i = 0; i < s.size(); i++)
        {
            if (ans.empty())
                ans.push_back(s[i]);
            else if (s[i] == ans.back())
                ans.pop_back();
            else
                ans.push_back(s[i]);
        }
        return ans;
    }
};
int main()
{
   
    return 0;
}