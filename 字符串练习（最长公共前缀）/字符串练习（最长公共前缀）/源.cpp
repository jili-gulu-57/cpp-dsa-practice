#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//14.最长公共前缀
//解法一：两两比较（已通过）
//class Solution {
//public:
//    string longestCommonPrefix(vector<string>& strs) {
//        string ans = strs[0];
//        for (int i = 1; i < strs.size(); i++)
//        {
//            ans = findcommon(ans, strs[i]);
//        }
//        return ans;
//    }
//    string findcommon(string& s1, string& s2)
//    {
//        int i = 0;
//        while (i < min(s1.size(), s2.size()) && s1[i] == s2[i])
//            i++;
//        return s1.substr(0, i);
//    }
//};

//解法二：一起比较（已通过）
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        for (int i = 0; i < strs[0].size(); i++)
        {
            char tmp = strs[0][i];
            int j = 1;
            while (j < strs.size())
            {
                if (i == strs[j].size() || strs[j][i] != tmp)
                    return strs[0].substr(0, i);
                else
                    j++;
            }
        }
        return strs[0];
    }
};

int main()
{
    string s1 = "flower";
    string s2 = "flow";
    string s3 = "flight";
    int ss = 2;
    printf("%c", s1[ss]);
    vector<string> strs;
    strs.push_back(s1);
    strs.push_back(s2);
    strs.push_back(s3);
    Solution s;
    s.longestCommonPrefix(strs);
    return 0;
}