#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


//67.二进制求和（已通过）
//原理：模拟列竖式计算
class Solution {
public:
    string addBinary(string a, string b) {
        int s1 = a.size(), s2 = b.size(), p1 = s1 - 1, p2 = s2 - 1, x = 0;
        string ans;
        while (p1 >=0 || p2 >=0 || x==1)
        {
            int tmp = 0;
            if (p1 >= 0)
                tmp += a[p1] - '0';
            if (p2 >= 0)
                tmp += b[p2] - '0';
            tmp += x;
            if (tmp ==2)
            {
                ans.push_back('0');
                x = 1;
            }
            else if (tmp == 3)
            {
                ans.push_back('1');
                x = 1;
            }
            else
            {
                ans.push_back(tmp + '0');
                x = 0;
            }
            p1--;
            p2--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};