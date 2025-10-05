#include<iostream>
using namespace std;


//991.坏了的计算器（已通过）
class Solution {
public:
    int brokenCalc(int s, int t) {
        int ans = 0;
        while (s != t)
        {
            if (t <= s)
                return (s - t + ans);
            else
            {
                if (t % 2 == 1)
                    t += 1;
                else
                    t /= 2;
                ans += 1;
            }
        }
        return ans;
    }
};