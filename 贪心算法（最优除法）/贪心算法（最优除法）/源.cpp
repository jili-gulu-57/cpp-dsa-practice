#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;


//553.最优除法（已通过）
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string ans;
        int n = nums.size();
        if (n == 1)
        {
            ans+=to_string(nums[0]);
            return ans;
        }
        else if (n == 2)
        {
            ans+=to_string(nums[0]);
            ans.push_back('/');
            ans+=to_string(nums[1]);
            return ans;
        }
        else
        {
            ans += to_string(nums[0]) + "/(";
            for (int i = 1; i < n; i++)
            {
                ans+=to_string((nums[i]));
                ans.push_back('/');
            }
            ans.back() = ')';
            return ans;
        }
    }
};

int main()
{
    vector<int> nums = { 1000, 100, 10,2 };
    Solution s;
    s.optimalDivision(nums);
    return 0;
}