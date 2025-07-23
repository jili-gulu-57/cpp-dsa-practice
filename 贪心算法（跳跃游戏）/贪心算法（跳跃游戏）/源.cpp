#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>

using namespace std;

//55.跳跃游戏（已通过）
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int left = 0, right = 0, n = nums.size();
        while (right < n - 1)
        {
            int tmp1 = left, tmp2 = right;
            left = right + 1;
            while (tmp1 <= tmp2)
            {
                right = max(right, nums[tmp1] + tmp1);
                tmp1++;
            }
            if (left > right)
                return false;
        }
        return true;
    }
};

int main()
{
    vector<int> nums = { 2,3,1,1,4 };
    Solution s;
    s.canJump(nums);
    return 0;
}