#include<iostream>
#include<vector>
using namespace std;

//978.最长湍流子数组
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size(), ans = 1;
        vector<int> f(n);   //上升
        vector<int> g(n);   //下降
        f[0] = g[0] = 1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[i - 1])
            {
                f[i] = g[i - 1] + 1;
                g[i] = 1;
            }
            else if (arr[i] < arr[i - 1])
            {
                f[i] = 1;
                g[i] = f[i - 1] + 1;
            }
            else
            {
                f[i] = 1;
                g[i] = 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            ans = max(f[i], ans);
            ans = max(g[i], ans);
        }
        return ans;
    }
};