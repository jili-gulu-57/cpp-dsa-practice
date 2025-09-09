#include<iostream>
#include<vector>
using namespace std;


//315.计算右侧小于当前元素的个数（已通过）
class Solution {
    vector<int> ret;
    vector<int> index;
    int TmpIndex[500010];
    int TmpNums[500010];
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ret.resize(n);
        index.resize(n);

        for (int i = 0; i < n; i++)
            index[i] = i;

        MergeSort(nums, 0, n - 1);
        return ret;
    }

    void MergeSort(vector<int>& nums, int left, int right)
    {
        if (left == right)
            return;

        int mid = (left + right) >> 1;
        MergeSort(nums, left, mid);
        MergeSort(nums, mid + 1, right);

        int cur1 = left, cur2 = mid + 1, i = 0;
        while (cur1 <= mid && cur2 <= right)
        {
            if (nums[cur1] <= nums[cur2])
            {
                TmpNums[i] = nums[cur2];
                TmpIndex[i++] = index[cur2++];
            }
            else
            {
                ret[index[cur1]] += right - cur2 + 1;
                TmpNums[i] = nums[cur1];
                TmpIndex[i++] = index[cur1++];

            }

        }
        while (cur1 <= mid)
        {
            TmpNums[i] = nums[cur1];
            TmpIndex[i++] = index[cur1++];
        }

        while (cur2 <= right)
        {
            TmpNums[i] = nums[cur2];
            TmpIndex[i++] = index[cur2++];
        }

        for (int j = left; j <= right; j++)
        {
            nums[j] = TmpNums[j - left];
            index[j] = TmpIndex[j - left];
        }
    }
};