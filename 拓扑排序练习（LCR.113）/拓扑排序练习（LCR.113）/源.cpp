#include<iostream>
#include<vector>
#include<queue>
using namespace std;


//LCR.113 课程表Ⅱ（已通过）
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //创建邻接图
        vector<vector<int>> edges(numCourses);
        vector<int> in(numCourses);

        //建表
        for (auto& v : prerequisites)
        {
            int a = v[0], b = v[1];
            edges[b].push_back(a);
            in[a]++;
        }

        //拓扑排序
        queue<int> q;
        vector<int> ans;
        for (int i = 0; i < numCourses; i++)
            if (in[i] == 0)
                q.push(i);

        while (q.size())
        {
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for (auto y : edges[x])
            {
                in[y]--;
                if (in[y] == 0)
                    q.push(y);
            }
        }
        if(ans.size()==numCourses)
            return ans;
        return {};
    }
};