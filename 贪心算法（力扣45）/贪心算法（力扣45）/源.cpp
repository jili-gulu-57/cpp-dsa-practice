#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


//45.跳跃游戏Ⅱ（已通过）
//利用层序遍历的思路，找出每次跳跃的左区间和右区间，当右区间大于n-1的时候，即找到了最少跳跃次数
class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0, left = 0, right = 0, n = nums.size();
        if (n == 1)
            return 0;
        while (right < (n-1))
        {
            int tmp1 = left, tmp2 = right;
            left = right + 1;
            while (tmp1<=tmp2)
            {
                right = max(right, tmp1 + nums[tmp1]);
                tmp1++;
            }
            ans++;
        }
        return ans;
    }
};
int main()
{
    vector<int> nums = { 2,3,1,1,4 };
    Solution s;
    s.jump(nums);
    return 0;
}