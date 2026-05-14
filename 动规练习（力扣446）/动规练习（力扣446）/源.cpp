#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//446.等差数列划分Ⅱ-子序列（已通过）
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        unordered_map<long long, vector<int>> hash;
        int ans = 0, n = nums.size();
        //题目要求元素最少三个，因此少于三个直接返回
        if (n < 3)
            return ans;

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            hash[nums[i]].push_back(i);
        }

        for (int i = 1; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                long long x = (long long)2 * nums[i] - nums[j];
                if (hash.count(x))
                {
                    for(auto k:hash[x])
                    {
                        if (k < i)
                            dp[i][j] += dp[k][i] + 1;
                    }
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = { 7,7,7,7,7 };
    //vector<int> nums = { 2,4,6,8,10};
    Solution s;
    cout<<s.numberOfArithmeticSlices(nums);
    return 0;
}