#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


//219.存在重复元素Ⅱ（已通过）
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++)
        {
            if (hash.count(nums[i]))
            {
                int tmp = i - hash[nums[i]];
                if (tmp <= k)
                    return true;
                hash[nums[i]] = i;
            }
            hash.insert({ nums[i], i });
        }
        return false;
    }
};