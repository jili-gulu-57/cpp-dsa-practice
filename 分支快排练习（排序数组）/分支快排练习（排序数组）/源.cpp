#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


//912.排序数组（已通过）
//存在重复数据，所以用“数组分三路的方式排序”
//选key值优化：
class Solution {
public:
    //产生一个随机数
    int getRandom(vector<int>& nums, int l, int r)
    {
        int ran = rand();
        return nums[ran % (r - l + 1) + l];
    }
    void quicksort(vector<int>& nums,int l, int r)
    {
        if (l >= r)
            return;
        //随机法取key值
        int key = getRandom(nums, l, r);
        int left = l - 1, right = r + 1, cur = l;
        while (cur<right)
        {
            if (key > nums[cur])
                swap(nums[++left], nums[cur++]);
            else if (key < nums[cur])
                swap(nums[--right], nums[cur]);
            else
                cur++;
            
        }
        quicksort(nums, l, left);
        quicksort(nums, right, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        //种下一棵随机种子
        srand(time(NULL));
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main()
{
    vector<int> nums = { 5,1,1,2,0,0 };
    Solution s;
    s.sortArray(nums);
    return 0;
}