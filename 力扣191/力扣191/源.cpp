#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//191.位1的个数（已通过）
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n)
        {
            if ((n & 1) == 1)
                count++;
            n = n >> 1;
        }
        return count;
    }
};
int main()
{
    Solution s;
    cout<<s.hammingWeight(128);
    return 0;
}