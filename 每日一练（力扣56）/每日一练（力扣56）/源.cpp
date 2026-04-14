#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//56.合并区间
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 1)
            return intervals;
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        int i = 1;
        int x1 = intervals[0][0];
        int y1 = intervals[0][1];
        for (; i < n; i++)
        {
            int x2 = intervals[i][0];
            int y2 = intervals[i][1];
            if (y1 >= y2)
            {
                ans.push_back({ x1,y1 });
            }
            else if (y1 >= x2)
            {
                ans.push_back({ x1,y2 });
            }
            else
            {
                ans.push_back({ x1,y1 });
            }
            x1 = ans.back()[0];
            y1 = ans.back()[1];
        }

        y1 = intervals[n - 1][1];
        int y2 = ans.back()[1];
        if (i<n && y1 != y2)
        {
            ans.push_back({ intervals[n - 1][0] ,intervals[n - 1][1] });
       }
        return ans;
    }
};

int main()
{
    //vector<vector<int>> i = { {1,3},{2,6},{8,10},{15,18} };
    vector<vector<int>> i = { {1,4},{0,2},{3,5} };
    Solution s;
    s.merge(i);
    return 0;
}