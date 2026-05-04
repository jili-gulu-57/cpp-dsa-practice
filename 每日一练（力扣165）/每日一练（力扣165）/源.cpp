#include<iostream>
#include<string>
#include<vector>
using namespace std;

//165.比较版本号（已通过）
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> nums1;
        vector<int> nums2;
        GetNums(version1, &nums1);
        GetNums(version2, &nums2);
        int p1 = 0, p2 = 0;
        while (p1 < nums1.size() && p2 < nums2.size())
        {
            if (nums1[p1] > nums2[p2])
                return 1;
            if (nums1[p1] < nums2[p2])
                return -1;
            p1++;
            p2++;
        }
        //修订号长，未遍历完
        while (p1 < nums1.size())
        {
            if (nums1[p1] > 0) //大于0才返回1
                return 1;
            p1++;
        }
        while (p2 < nums2.size())
        {
            if (nums2[p2] > 0)
                return -1;
            p2++;
        }
        return 0;
    }
    //获取字符串的数字
    void GetNums(const string& version,vector<int>*nums)
    {
        int num = 0;
        for (int i = 0; i < version.size(); i++)
        {
            if (version[i] != '.')
            {
                num *= 10;
                num = num + (version[i] - '0');
            }
            else
            {
                nums->push_back(num);
                num = 0;
            }
        }
        nums->push_back(num);//将最后一个数字push进去
    }
};

int main()
{
    Solution s;
    s.compareVersion("1.0", "1.0.0.0");
    return 0;
}