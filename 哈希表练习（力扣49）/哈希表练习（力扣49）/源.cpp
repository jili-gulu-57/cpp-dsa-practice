#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

//49.字母异位词分组（已通过）
//将所有字母异位词排序后分组
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for (auto& s : strs)
        {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            hash[tmp].push_back(s);
        }
        //提取value
        vector<vector<string>> ans;
        for (auto& [x, y] : hash)
            ans.push_back(y);
        return ans;
    }
};