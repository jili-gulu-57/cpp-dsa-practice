#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//已通过
class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> hash(26);
        int count = 0;
        char maxchar = ' ';
        //统计每个字符出现的次数
        for (auto e : s)
        {
            hash[e - 'a']++;
            if (count < hash[e - 'a'])
            {
                count = hash[e - 'a'];
                maxchar = e;
            }
        }
        // 检查是否可以重构：如果最大出现次数超过(n+1)/2，则无法重构
        if (count > (n + 1) / 2)
            return "";

        int index = 0;
        string ans(n, ' ');
        //隔位填充最大字符
        for (int i = 0; i < count; i ++)
        {
            ans[index] = maxchar;
            index += 2;
        }
        hash[maxchar - 'a'] = 0;

        for (int i = 0; i < 26; i++)
        {
            //注意j<hash[i]的条件
            for (int j = 0; j < hash[i]; j++)
            {
                if (index >= n)
                    index = 1;
                ans[index] = 'a' + i;
                //这步保证如果存在出现相同次数的最大字符，仍然隔位放置
                index += 2;
            }
        }
        return ans;
    }
};
int main()
{
    string s = "bfrbs";
    Solution ss;
    ss.reorganizeString(s);
    return 0;
}