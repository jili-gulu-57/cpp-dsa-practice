#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//870.优势洗牌（已通过）
//#include<algorithm>
//class Solution {
//public:
//    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
//        int n = nums1.size();
//        vector<int> index(n);
//        vector<int> ans(n);
//        for (int i = 0; i < n; i++)
//            index[i] = i;
//        //根据nums2数组对index数组进行排序
//        sort(nums1.begin(), nums1.end());
//        sort(index.begin(), index.end(), [&](int i, int j)
//            {
//                return nums2[i] < nums2[j];
//            });
//        int left = 0, right = n - 1, pre = 0;
//        while (pre < n)
//        {
//            if (nums1[pre] > nums2[index[left]])
//            {
//                ans[index[left]] = nums1[pre];
//                left++;
//            }
//            else
//            {
//                ans[index[right]] = nums1[pre];
//                right--;
//            }
//            pre++;
//        }
//        return ans;
//    }
//};


//409.最长回文串（已通过）
//class Solution {
//public:
//    int longestPalindrome(string s) {
//        int ans = 0, flag = 0;
// //‘A’的ASCII码值为65，‘z’的ASCII码值为122，122-65=57，所以数组大小应该设置为58，否则对应下标时会越界
//        vector<int> count(58);
//        for (auto c : s)
//            count[c - 'A']++;
//        for (auto e : count)
//        {
//            if (e % 2 == 0)
//                ans += e;
//            else
//            {
//                flag = 1;
//                ans += e - 1;
//            }
//        }
//        if (flag)
//            return ans + 1;
//        return ans;
//    }
//};
//int main()
//{
//    string  s = "zeusnilemacaronimaisanitratetartinasiaminoracamelinsuez";
//    Solution ss;
//    ss.longestPalindrome(s);
//    return 0;
//}


//942.增减字符串匹配（已通过）
#include<deque>
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int> ans(n + 1);
        deque<int> nums(n + 1);
        for (int i = 0; i <= n; i++)
            nums[i] = i;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'I')
            {
                ans[i] = nums.front();
                nums.pop_front();
            }
            else
            {
                ans[i] = nums.back();
                nums.pop_back();
            }
        }
        ans[n] = nums.back();
        return ans;
    }
};
int main()
{
    string s = "IDID";
    Solution ss;
    ss.diStringMatch(s);
    return 0;
}