#include<iostream>
#include<vector>
using namespace std;


//152.乘积最大子数组（已通过）
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), ans = nums[0];
        vector<int> f(n);
        vector<int> g(n);
        f[0] = nums[0], g[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            int tmp1 = f[i - 1] * nums[i];
            int tmp2 = g[i - 1] * nums[i];
            f[i] = max(tmp1, nums[i]);
            f[i] = max(tmp2, f[i]);
            g[i] = min(tmp1, nums[i]);
            g[i] = min(tmp2, g[i]);
            ans = max(ans, f[i]);
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = { -2,-3,7 };
    Solution s;
    s.maxProduct(nums);
    return 0;
}