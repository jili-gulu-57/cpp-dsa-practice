#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//88.合并两个有序数组（已通过）
//从后往前遍历，将大的数据放在nums1后面，可避免出现nums1后面数据为0的情况
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0)
            return;
        if (m == 0)
        {
            nums1 = nums2;
            return;
        }
        int p1 = m - 1, p2 = n - 1, index = (m + n) - 1;
        while (p1>=0 && p2>=0)
        {
            if (nums2[p2] >= nums1[p1]  )
            {
                nums1[index] = nums2[p2];
                p2--;
                index--;
            }
            else
            {
                nums1[index] = nums1[p1];
                p1--;
                index--;
            }
        }
        while (p2 >= 0)
        {
            nums1[p2] = nums2[p2];
            p2--;
        }
    }
};