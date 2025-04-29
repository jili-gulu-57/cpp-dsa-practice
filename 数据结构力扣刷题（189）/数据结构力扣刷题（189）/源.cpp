#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//189.轮转数组
//思路：先逆置后k个元素，再逆置前n-k个元素，最后再整体逆置(空间复杂度为O(1))
class Solution {
public:
    void reverse(vector<int>& nums, int left, int right)
    {
        while (left < right)
        {
            int tmp = 0;
            tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            left++;
            right--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - k - 1);
        reverse(nums, 0, n - 1);
    }
};