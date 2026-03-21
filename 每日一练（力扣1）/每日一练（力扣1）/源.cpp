#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//1.两数之和（已通过）
//哈希表存储数据和下标
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> hash(n);
        //1.将所有数据存入哈希表中
        for (int i = 0; i < n; i++)
        {
            hash.insert({ nums[i], i });
        }

        //2.遍历哈希表搜素数据
        for (int i = 0; i < n; i++)
        {
            int x = target - nums[i];
            auto y = hash.find(x);
            if (y != hash.end() && y->second != i)
            {
                return { i,y->second };
            }
        }
        //因为一定有答案，但防止编译器报错返回一个随机值
        return { 0,1 };
    }
};

int main()
{
    vector<int> nums = { 3,2,4};
    Solution s;
    s.twoSum(nums, 6);
    return 0;
}