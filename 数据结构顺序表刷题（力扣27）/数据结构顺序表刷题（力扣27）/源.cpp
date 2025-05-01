#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//27.移除元素
//左右双指针（已通过）
//class Solution {
//public:
//    int removeElement(vector<int>& nums, int val) {
//        int left = 0, right = nums.size() - 1, count = nums.size();
//        while (left < right)
//        {
//            if (nums[left] == val && nums[right] != val)
//            {
//                swap(nums[left], nums[right]);
//                left++;
//                right--;
//            }
//            if (nums[left] == val && nums[right] == val)
//            {
//                right--;
//            }
//            if(nums[left]!=val)
//                left++;
//        }
//        for (auto x : nums)
//        {
//            if (x == val)
//                count--;
//        }
//        return count;
//    }
//};

//快慢双指针（已通过）
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int src = 0, dst = 0, count = nums.size();
        while (src < nums.size())
        {
            if (nums[src] != val)
            {
                swap(nums[src], nums[dst]);
                src++;
                dst++;
            }
            else
            {
                count--;
                src++;
            }
        }
        return count;
    }
};
int main()
{
    vector<int> nums = { 0,1,2,2,3,0,4,2 };
    Solution s;
    s.removeElement(nums, 2);
    return 0;
}