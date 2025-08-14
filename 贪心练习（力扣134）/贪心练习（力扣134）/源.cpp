#include<iostream>
#include<vector>
#include<queue>
using namespace std;


//134.加油站
//解法一：暴力枚举（时间会超限）
//class Solution {
//public:
//    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//        int n = gas.size();
//        vector<int> dif(n);
//        queue<int> ans;    //保存是正数的下标
//        for (size_t i = 0; i < n; i++)
//        {
//            dif[i] = gas[i] - cost[i];
//            if (dif[i] >= 0)
//                ans.push(i);
//        }
//        while (ans.size())
//        {
//            int fia = 0;
//            int index = ans.front();
//            ans.pop();
//            for (int i = 0; i < n; i++)
//            {
//                if (fia < 0)
//                    break;
//                fia += dif[(index + i) % n];
//            }
//            if (fia >= 0)
//                return index;
//        }
//        return -1;
//    }
//};

//解法二：贪心算法（已通过）
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < n; i++)
        {
            int rest = 0;
            for (int step = 0; step < n; step++)
            {
                rest += gas[(i + step) % n] - cost[(i + step) % n];
                if (rest < 0)
                {
                    i = i + step;
                    break;
                }
            }
            if (rest >= 0)
                return i;
        }
        return -1;
    }
};

int main()
{
    vector<int> gas = { 2,3,4 };
    vector<int> cost = { 3,4,3 };
    Solution s;
    cout<<s.canCompleteCircuit(gas, cost);

    return 0;
}