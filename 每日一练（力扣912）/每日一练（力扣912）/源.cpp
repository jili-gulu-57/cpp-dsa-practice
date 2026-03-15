#include<iostream>
#include<vector>
using namespace std;

//912.排序数组（已通过）
class Solution {
    //产生一个随机数（必须取随机数，否则在部分情况下空间复杂度会退化如，3,2,2,2,2...）
    int getRandom(vector<int>& nums, int l, int r)
    {
        int ran = rand();
        return (ran % (r - l + 1) + l);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        QuickSort(nums, 0, n - 1);
        return nums;
    }
    //快排
    void QuickSort(vector<int>& nums, int begin, int end)
    {
        //递归出口
        if (begin >= end)
            return;

        int l = begin, r = end, pivot = getRandom(nums, begin, end);
        swap(nums[l], nums[pivot]);
        pivot = nums[l];
        while (l < r)
        {
            while (l < r && nums[r] >= pivot)
            {
                r--;
            }
            nums[l] = nums[r];

            while (l < r && nums[l] <= pivot)
            {
                l++;
            }
            nums[r] = nums[l];
        }
        nums[l] = pivot;
        QuickSort(nums, begin, l - 1);
        QuickSort(nums, r + 1, end);
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 5,3,2,1 };
    s.sortArray(nums);
    return 0;
}