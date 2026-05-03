#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//1218.最长定差子序列（已通过）
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> hash;
        int ans = 1;
        hash[arr[0]] = 1;
        for (int i = 1; i < arr.size(); i++)
        {
            int tar = arr[i] - difference;
            hash[arr[i]] = hash[tar] + 1;
            ans = max(ans, hash[arr[i]]);
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = { 1,3,5,7 };
    Solution s;
    s.longestSubsequence(arr, 1);
    return 0;
}