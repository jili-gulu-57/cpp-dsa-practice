#include<iostream>
#include<vector>
using namespace std;

//46.全排列（已通过）
class Solution {
    vector<int> a;
    vector<vector<int>> ans;
    int n;
    bool check[6] = { 0 };
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        dfs(nums);
        return ans;
    }
    void dfs(vector<int>& nums)
    {
        if (a.size() == n)
        {
            ans.push_back(a);
            return;
        }
        for(int i = 0 ; i < n ; i++)
        {
            if (!check[i])
            {
                a.push_back(nums[i]);
                check[i] = true;
                dfs(nums);
                //恢复现场
                check[i] = false;
                a.pop_back();
            }
        }
    }
};

int main()
{
    vector<int> nums = { 1,2,3 };
    Solution s;
    s.permute(nums);
    return 0;
}