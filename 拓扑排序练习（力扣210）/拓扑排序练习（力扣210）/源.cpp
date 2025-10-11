#include<iostream>
#include<vector>
#include<queue>
using namespace std;


//210.课程表Ⅱ（已通过）
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>edgs(numCourses);
        vector<int>in(numCourses);
        for (auto& v : prerequisites)
        {
            int a = v[0], b = v[1];
            edgs[b].push_back(a);
            in[a]++;
        }
        queue<int>q;
        vector<int> ans;
        for (int i=0;i<numCourses;i++)
        {
            if (in[i] == 0)
                q.push(i);
        }
        while (q.size())
        {
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for (int a : edgs[x])
            {
                in[a]--;
                if (in[a] == 0)
                    q.push(a);
            }
        }
        if (ans.size() == numCourses)
            return ans;
        ans.resize(0);
        return ans;
    }
};