#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//461.汉明距离（已通过）
class Solution {
public:
    int hammingDistance(int x, int y) {
        int m = x ^ y, count = 0;
        while (m)
        {
            if ((m & 1) == 1)
                count++;
            m = m >> 1;
        }
        return count;
    }
};