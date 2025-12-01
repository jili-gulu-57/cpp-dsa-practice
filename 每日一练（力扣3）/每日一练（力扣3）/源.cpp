#include<iostream>
#include<string>
#include<unordered_map> //键值对哈希表
using namespace std;


//3.无重复字符的最长子串（已通过）
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (!s.size())
            return 0;
        int ans = 1, l1 = 0, l2 = 1;
        //哈希表加滑动窗口
        unordered_map<int, int> hash;
        hash.insert({ s[l1], l1 });
        while (l2 < s.size())
        {
            //存在重复元素
            if (hash.count(s[l2])&&hash[s[l2]]>=l1) //l1指针更新，那么指针前的字符不作为判断重复的标准
            {
                //更新l1指针
                l1 = hash[s[l2]] + 1;
                hash[s[l2]] = l2;
            }
            else
            {
                hash[s[l2]] = l2;   //保证值可以更新
                //hash.insert({ s[l2],l2 });//使用insert重复插入键时，值不会更新
            }
            l2++;
            //更新ans
            ans = max(ans, l2 - l1);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout<<s.lengthOfLongestSubstring("aabaab!bb");

    switch (switch_on)
    {
    default:
        break;
    }

    return 0;
}