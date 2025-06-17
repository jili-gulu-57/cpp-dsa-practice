#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


//面试题01.01.判断字符是否唯一（已通过）
//class Solution {
//public:
//    bool isUnique(string astr) {
//        if (astr.size() > 26)
//            return false;
//        int bitmap = 0;
//        for (auto ch : astr)
//        {
//            int i = ch - 'a';
//            if (((bitmap >> i) & 1) == 1)
//                return false;
//            bitmap |= (1 << i);
//        }
//        return true;
//    }
//};


//268.丢失的数字（均已通过）
//解法一：将数组排序后，依次与0~n的数进行比较
//#include<algorithm>
//class Solution {
//public:
//    int missingNumber(vector<int>& nums) {
//        int n = nums.size();
//        sort(nums.begin(), nums.end());
//        for (int i = 0; i < n; i++)
//        {
//            if (nums[i] != i)
//                return i;
//        }
//        return n;
//    }
//};
//解法二：高斯求和
//class Solution {
//public:
//    int missingNumber(vector<int>& nums) {
//        int n = nums.size();
//        int sum = ((1 + n) * n) / 2;
//        for (int i = 0; i < n; i++)
//            sum -= nums[i];
//        return sum;
//    }
//};
//解法三：异或，将0~n所有的数字和数组的数字异或在一起，相同的数字异或结果为0，0异或任意数字都是这个数字本身
//class Solution {
//public:
//    int missingNumber(vector<int>& nums) {
//        int n = nums.size();
//        int ans = 0;
//        for (int i = 0; i < n; i++)
//            ans^=(nums[i] ^ i);
//        ans ^= n;
//        return ans;
//    }
//};
//int main()
//{
//    vector<int> nums = { 0,1 };
//    Solution s;
//    s.missingNumber(nums);
//    return 0;
//}


//371.两整数之和（已通过）
//按位异或是无进位相加，所以需要找到 进位 的位置，二进制中只有1+1才会有进位，而位运算中只有按位与是二进制位同时为1才为1，此时只需要再将按位与的结果左移一位就可以找到需要进位的位置。
//重复上述步骤，直到按位与的结果为0，即无进位时，此时按位异或的结果就是相加结果。
//class Solution {
//public:
//    int getSum(int a, int b) {
//        int x = a ^ b, y = (a & b) << 1;
//        while (y)
//        {
//            int tmp = x;
//            x = x ^ y;
//            y = (tmp & y) << 1;
//        }
//        return x;
//    }
//};
//int main()
//{
//    Solution s;
//    cout<<s.getSum(12, 43);
//    return 0;
//}


//137.只出现一次的数字Ⅱ（已通过）
//class Solution {
//public:
//    int singleNumber(vector<int>& nums) {
//        int ans = 0;
//        for (int i = 0; i < 32; i++)
//        {
//            int sum = 0;
//            for (int x : nums)
//            {
//                if (((x >> i) & 1) == 1)
//                {
//                    sum++;
//                }
//            }
//            sum %= 3;
//            if (sum == 1)
//                ans |= (1 << i);
//        }
//        return ans;
//    }
//};



//面试题17.19.消失的两个数字（已通过）
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int tmp = 0;
        for (auto x : nums)
            tmp ^= x;
        for (int i = 1; i <= nums.size() + 2; i++)
            tmp ^= i;

        int dif = 0;
        while (1)
        {
            if (((tmp >> dif) & 1) == 1)
                break;
            else
                dif++;
        }
        int a = 0, b = 0;
        for (int i = 1; i <= nums.size() + 2; i++)
            if (((i >> dif) & 1) == 0)
                a ^= i;
            else
                b ^= i;
        for(auto x:nums)
            if (((x >> dif) & 1) == 0)
                a ^= x;
            else
                b ^= x;
        return { a,b };
    }
};