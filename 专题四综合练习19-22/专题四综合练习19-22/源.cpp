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



//39.组合总和
//解法一：普通dfs（已通过）
//class Solution {
//public:
//    vector<vector<int>> ans;
//    vector<int> path;
//    int aim;
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//        aim = target;
//        dfs(candidates, 0, 0);
//
//    }
//    void dfs(vector<int>& candidates, int pos, int sum)
//    {
//        if (sum == aim)
//        {
//            ans.push_back(path);
//            return;
//        }
//
//        if (sum > aim || pos == candidates.size())
//            return;
//
//        for (int i = pos; i < candidates.size(); i++)
//        {
//            path.push_back(candidates[i]);
//            //因为可以重复选择，所以第二个参数是i
//            dfs(candidates, i, sum + candidates[i]);
//
//            //恢复现场
//            path.pop_back();
//        }
//    }
//};
//解法二：枚举个数（已通过）
//class Solution {
//public:
//    vector<int> path;
//    vector<vector<int>> ans;
//    int aim;
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//        aim = target;
//        dfs(candidates, 0, 0);
//        return ans;
//    }
//    void dfs(vector<int>& candidates, int pos, int sum)
//    {
//        if (sum == aim)
//        {
//            ans.push_back(path);
//            return;
//        }
//
//        if (sum > aim || pos == candidates.size())
//            return;
//
//        for (int k = 0; k * candidates[pos] <= aim; k++)
//        {
//            if (k)
//                path.push_back(candidates[pos]);
//            dfs(candidates, pos + 1, sum + k * candidates[pos]);
//        }
//
//        for (int k = 1; k * candidates[pos] <= aim; k++)
//        {
//            path.pop_back();
//        }
//    }
//};

int b;
int c = 10;
int main()
{
	int a = 10;
	printf("%p\n", main);
	printf("a: %p\n", &a);
	printf("b: %p\n", &b);
	printf("c: %p\n", &c);
	return 0;
}