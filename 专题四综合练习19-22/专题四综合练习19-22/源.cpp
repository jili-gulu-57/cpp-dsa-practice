#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//77.组合（已通过）
//class Solution {
//    vector<vector<int>> ans;
//    vector<int> path;
//    int n, k;
//public:
//    vector<vector<int>> combine(int _n, int _k) {
//        n = _n;
//        k = _k;
//        dfs(1);
//        return ans;
//    }
//    void dfs(int start)
//    {
//        if (path.size() == k)
//        {
//            ans.push_back(path);
//            return;
//        }
//        for (int i = start; i <= n; i++)
//        {
//            path.push_back(i);
//            dfs(i + 1);
//            path.pop_back();
//        }
//    }
//};


//494.目标和（已通过）
//class Solution {
//public:
//    int ans;
//    int target;
//    int findTargetSumWays(vector<int>& nums, int _target) {
//        target = _target;
//        dfs(nums, 0, 0);
//        return ans;
//    }
//    void dfs(vector<int>& nums, int i,int sum)
//    {
//        if (i == nums.size())
//        {
//            if (sum == target)
//                ans++;
//            return;
//        }
//        //加法
//        sum += nums[i];
//        dfs(nums, i + 1, sum);
//        sum -= nums[i];//恢复现场
//        //减肥
//        sum -= nums[i];
//        dfs(nums, i + 1, sum);
//    }
//};


