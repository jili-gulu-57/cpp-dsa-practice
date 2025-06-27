#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//面试题01.02.判断是否互为字符重排（已通过）
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        //可能出现长度不一样的情况，无需判断，直接返回
        if (s1.size() != s2.size())
            return false;
        vector<int> hash1(26);
        vector<int> hash2(26);
        for (auto c : s1)
            hash1[c - 'a']++;
        for (auto c : s2)
            hash2[c - 'a']++;
        for (int i = 0; i < 26; i++)
        {
            if (hash1[i] != hash2[i])
                return false;
        }
        return true;
    }
};
//解法二：只创建一个hash表，用该表遍历第二个字符串（已通过）
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        //可能出现长度不一样的情况，无需判断，直接返回
        if (s1.size() != s2.size())
            return false;
        vector<int> hash(26);
        for (auto c : s1)
            hash[c - 'a']++;
        for (auto c : s2)
            hash[c - 'a']--;
        for (int i = 0; i < 26; i++)
            if (hash[i])
                return false;
        return true;
    }
};

int main()
{
    string s1 = "cuhv";
    string s2 = "cuvs";
    Solution s;
    s.CheckPermutation(s1, s2);
    return 0;
}