#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;


//844.比较含退格的字符串（已通过）
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a, b;
        for (auto ch : s)
        {
            if (ch != '#')
                a.push_back(ch);
            else if (a.size())
                a.pop_back();
        }
        for (auto ch : t)
        {
            if (ch != '#')
                b.push_back(ch);
            else if (b.size())
                b.pop_back();
        }
        return a == b;
    }
};