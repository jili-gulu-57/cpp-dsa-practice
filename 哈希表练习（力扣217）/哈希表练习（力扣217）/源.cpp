#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>  
#include<vector>
#include<unordered_set>
using namespace std;


//217.存在重复元素（已通过）、
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash;
        for (auto x : nums)
        {
            if (hash.count(x))
                return true;
            hash.insert(x);
        }
        return false;
    }
};