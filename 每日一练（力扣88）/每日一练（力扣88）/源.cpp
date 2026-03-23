#include<iostream>
#include<vector>
using namespace std;

//88.合并两个有序数组（已通过）
//注意元素下标需根据数组2进行变化
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l1 = 0, l2 = 0;
        while (l1 < m+n && l2 < n)
        {
            while (nums1[l1] <= nums2[l2])
            {
                l1++;
                if (l1 >= m + l2)
                    break;
            }
            if (l1 >= m + l2)
                break;

            //先将当前位置元素向后挪
            int pos1 = m - 1 + l2, pos2 = pos1 + 1;
            while (pos1 >= l1)
            {
                nums1[pos2] = nums1[pos1];
                pos1--;
                pos2--;
            }
            //插入nums2元素
            nums1[l1] = nums2[l2];
            l1++;
            l2++;
        }
        while (l2 < n)
        {
            nums1[m + l2] = nums2[l2];
            l2++;
        }
    }
};

void Print(vector<int>& nums)
{
    for (auto i : nums)
        cout << i << " ";
}

int main()
{
    vector<int> nums1 = { -1,0,1,1,0,0,0,0,0 };
    vector<int> nums2 = { -1,0,2,2,3 };
    Solution s;
    s.merge(nums1, 4, nums2, nums2.size());
    Print(nums1);
    return 0;
}
