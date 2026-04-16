#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//56.合并区间（已通过）
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 1)
            return intervals;
        sort(intervals.begin(), intervals.end());
        vector<int> nums;
        for (int i = 0; i < n; i++)
        {
            nums.push_back(intervals[i][0]);
            nums.push_back(intervals[i][1]);
        }

        vector<vector<int>> ans;
        int begin = 0, m = 0;
        for (int i = 1; i < 2 * n - 1; i++)
        {
            m = nums[i];
            while ((i < 2 * n - 1) && (m >= nums[i + 1] || i % 2 == 0))
            {
                i++;
                m = max(nums[i], m);
            }
            ans.push_back({ nums[begin],max(m,nums[i])});
            begin = i + 1;
            i ++;
            if (i == 2 * n - 2)
            {
                ans.push_back({ nums[i],nums[i + 1] });
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> i = { {1,3},{2,6},{8,10},{15,18} };
    //vector<vector<int>> i = { {2,3},{4,5},{6,7},{8,9},{1,10} };
    //vector<vector<int>> i = { {1,4},{2,3} };
    //vector<vector<int>> i = { {1,4},{0,2},{3,5} };
    Solution s;
    s.merge(i);
    return 0;
}