#include<iostream>
#include<string>
using namespace std;


//738.单调递增的数字（已通过）
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        //找到开始递减的位置
        string s = to_string(n);
        int m = s.size();
        int i = 0;
        for (; i < m - 1; i++)
        {
            if (s[i] > s[i + 1])
                break;
        }
        if (i == m - 1)
            return n;
        //往前遍历，看看是否有与它相同的数字
        for (; i > 0; i--)
        {
            if (s[i - 1] != s[i])
                break;
        }
        //只用减小当前数字
        s[i]--;
        //把剩下数字全改成9
        while (i < m - 1)
        {
            s[++i] = 9 + '0';
        }
        //将字符串转换为整数
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            ans *= 10;
            ans += s[i] - '0';
        }
        return ans;
    }
};

int main()
{
    int x = 10;
    Solution s;
    s.monotoneIncreasingDigits(x);
    return 0;
}