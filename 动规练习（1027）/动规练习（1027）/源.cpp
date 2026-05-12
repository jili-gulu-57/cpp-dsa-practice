#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//1027.最长等差子序列（已通过）
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(), ans = 2;
        unordered_map<int, int> hash;
        vector<vector<int>> dp(n, vector<int>(n, 2));
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                hash[nums[i - 1]] = i - 1;
                int x = 2 * nums[i] - nums[j];
                if (hash.find(x) != hash.end() && hash[x] < i)
                {
                    dp[i][j] = dp[hash[x]][i] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = { 3,6,9,12 };
    Solution s;
    cout << s.longestArithSeqLength(nums);
    return 0;
}