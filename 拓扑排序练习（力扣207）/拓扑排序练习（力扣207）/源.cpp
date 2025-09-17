#include<iostream>
#include<vector>
#include<queue>
using namespace std;


//207.课程表（已通过）
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);  //邻接表建图
        vector<int> in(numCourses); //统计每个节点的入度

        //建图
        for (auto v : prerequisites)
        {
            int a = v[0], b = v[1];
            in[a]++;    //入度增加
            edges[b].push_back(a);
        }

        //拓扑排序
        //将所有入度为0的点加入队列
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (in[i] == 0)
                q.push(i);
        }

        //逐步去点
        while (q.size())
        {
            int x = q.front();
            q.pop();
            for (int a : edges[x])
            {
                in[a]--;
                if (in[a] == 0)
                    q.push(a);
            }
        }

        //判断是否有环
        for (int c : in)
            if (c)
                return false;
        return true;
    }
};

int main()
{
    vector<vector<int>> prerequisites = { {1,0} };
    int n = 2;
    Solution s;
    s.canFinish(n, prerequisites);
    return 0;
}