#include<iostream>
#include<vector>
using namespace std;


//215.数组中的第K个最大元素（已通过）
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(NULL));
        qsort(nums, 0, nums.size() - 1, k);
        return nums[k - 1];
    }
    void qsort(vector<int>& nums, int l, int r, int k)
    {
        if (l == r)
            return;
        //随机选择基准元素
        int key = GetRandom(nums, l, r);
        int left = l - 1, right = r + 1, i = l;
        while (i<right)
        {
            if (nums[i] > key)
                swap(nums[i++], nums[++left]);
            else if (nums[i] < key)
                swap(nums[i], nums[--right]);//i不能++，因为不知道nums[-right]与key相比值的大小，需要再次检查
            else 
                i++;
        }
        int a = left - l + 1, b = right - left - 1;
        if (a >= k)
            qsort(nums, l, left, k);
        else if ((a + b) >= k)
            return;
        else 
            qsort(nums, right, r, k - a - b);

    }
    int GetRandom(vector<int>& nums, int left,int right)
    {
        return nums[rand() % (right - left + 1) + left];
    }
};

int main()
{
    vector<int> nums = { 7,4,3,4,5,4, 2 };
    Solution s;
    cout << s.findKthLargest(nums, 2);
    return 0;
}