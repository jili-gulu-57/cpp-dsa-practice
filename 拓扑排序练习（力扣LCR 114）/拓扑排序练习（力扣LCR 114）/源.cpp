#include<iostream>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;

//LCR 114.火星词典（已通过）
class Solution {
    unordered_map<char, unordered_set<char>> edges;
    bool check;
    unordered_map<char, int> in;
public:
    string alienOrder(vector<string>& words) {
        //1.建图+初始化入度
        for (auto& s : words)
        {
            for (auto ch : s)
                in[ch] = 0;
        }
        int n = words.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                add(words[i], words[j]);
                if (check)
                    return "";
            }
        }

        //2.拓扑排序
        queue<char> q;
        for (auto& [a, b] : in)
        {
            if (b == 0)
                q.push(a);
        }
        string ans;
        while (q.size())
        {
            char t = q.front();
            q.pop();
            ans += t;
            for (char ch : edges[t])
            {
                if (--in[ch] == 0)
                    q.push(ch);
            }
        }
         //3.判断
        for (auto& [a, b] : in)
        {
            if (b != 0)
                return "";
        }
        return ans;
    }

    void add(string& words1, string& words2)
    {
        int n = min(words1.size(), words2.size());
        int i = 0;
        for (; i < n; i++)
        {
            if (words1[i] != words2[i])
            {
                char a = words1[i], b = words2[i];
                if (!edges.count(a) || !edges[a].count(b))
                {
                    in[b]++;
                    edges[a].insert(b);
                }
                break;
            }
        }
        if (i == words2.size() && i < words1.size())
            check = true;
    }
};