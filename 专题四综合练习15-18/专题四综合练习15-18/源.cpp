#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//1863.找出所有子集的异或总和再求和（已通过）
//class Solution {
//    int yihuo;
//    int sum;
//    vector<int> path;
//public:
//    int subsetXORSum(vector<int>& nums) {
//        dfs(nums, 0);
//        return sum;
//    }
//    void dfs(vector<int>& nums, int pos)
//    {
//        int i = pos;
//        for (i = pos; i < nums.size(); i++)
//        {
//            path.push_back(nums[i]);
//            dfs(nums, i + 1);
//            path.pop_back();
//        }
//        yihuo = 0;
//        for (auto num : path)
//            yihuo ^= num;
//        sum += yihuo;
//        return;
//    }
//};
//int main()
//{
//    vector<int> nums = {1,3};
//    Solution s;
//    cout<<s.subsetXORSum(nums);
//    return 0;
//}


//47.全排列Ⅱ（已通过）
//#include<algorithm>
//class Solution {
//    vector<int> path;
//    vector<vector<int>> ans;
//    bool check[9];
//    int n;
//public:
//    vector<vector<int>> permuteUnique(vector<int>& nums) {
//        n = nums.size();
//        sort(nums.begin(), nums.end());
//        dfs(nums, 0);
//        return ans;
//    }
//    //只关心不合法分支，将不合法分支减去
//    //void dfs(vector<int>& nums, int pos)
//    //{
//    //    if (pos == n)
//    //    {
//    //        ans.push_back(path);
//    //        return;
//    //    }
//    //    for (int i = 0; i < n; i++)
//    //    {
//    //        //剪枝
//    //        if (check[i] == true || (i != 0 && nums[i] == nums[i - 1] && check[i - 1] == false))
//    //            continue;
//    //        path.push_back(nums[i]);
//    //        check[i] = true;
//    //        dfs(nums, pos + 1);
//    //        path.pop_back();
//    //        check[i] = false;
//    //    }
//    //}
//    //只关心合法分支
//    void dfs(vector<int>& nums, int pos)
//    {
//        if (pos == n)
//        {
//            ans.push_back(path);
//            return;
//        }
//        for (int i = 0; i < n; i++)
//        {
//            if (check[i] == false && (i == 0 || nums[i] != nums[i - 1] || check[i - 1] == true))
//            {
//                path.push_back(nums[i]);
//                check[i] = true;
//                dfs(nums, pos + 1);
//                path.pop_back();
//                check[i] = false;
//            }
//        }
//    }
//};
//int main()
//{
//    vector<int> nums = { 1,2,3 };
//    Solution s;
//    s.permuteUnique(nums);
//    return 0;
//}


//17.电话号码的字母组合（已通过）
//class Solution {
//    int n;
//    vector<string> hash = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
//    string path;
//    vector<string> ans;
//public:
//    vector<string> letterCombinations(string digits) {
//        n = digits.size();
//        if (n == 0)
//            return ans;
//        dfs(digits, 0);
//        return ans;
//    }
//    void dfs(string& digits, int pos)
//    {
//        if (pos == n)
//        {
//            ans.push_back(path);
//            return;
//        }
//        for (auto ch : hash[digits[pos] - '0'])
//        {
//            path.push_back(ch);
//            dfs(digits, pos + 1);
//            path.pop_back();
//        }
//    }
//};


//22.括号生成（已通过）
class Solution {
public:
    int left, right, count;
    string path;
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        count = n;
        dfs();
        return ans;
    }
    void dfs()
    {
        if (right == count)
        {
            ans.push_back(path);
            return;
        }
        if (left < count)
        {
            path.push_back('(');
            left++;
            dfs();
            path.pop_back();
            left--;
        }
        if (left > right)
        {
            path.push_back(')');
            right++;
            dfs();
            path.pop_back();
            right--;
        }
    }
};
int main()
{
    Solution s;
    s.generateParenthesis(3);
    return 0;
}