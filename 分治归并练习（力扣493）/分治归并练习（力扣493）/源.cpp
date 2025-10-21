#include<iostream>
#include<vector>
using namespace std;

//493.翻转对
//降序（已通过）
//class Solution {
//    int tmp[50001];
//public:
//    int reversePairs(vector<int>& nums) {
//        return mergeSort(nums, 0, nums.size() - 1);
//    }
//    int mergeSort(vector<int>& nums, int left, int right)
//    {
//        if (left == right)
//            return 0;
//        int ans = 0;
//        int mid = (left + right) >> 1;
//        ans += mergeSort(nums, left, mid);
//        ans += mergeSort(nums, mid + 1, right);
//
//        int cur1 = left, cur2 = mid + 1;
//
//        //统计翻转对
//        while (cur1 <= mid)
//        {
//            while (cur2 <= right && nums[cur1]/2.0 <= nums[cur2])
//            {
//                cur2++;
//            }
//            
//            //right为数组最后位置的下标，而非元素个数
//            if(cur2>right)
//                break;
//            else
//            {
//                ans += right - cur2 + 1;
//                cur1++;
//            }
//        }
//
//        //归并排序（降序）
//        cur1 = left, cur2 = mid + 1;
//        int i = left;
//        while (cur1 <= mid && cur2 <= right)
//        {
//            if (nums[cur1] >= nums[cur2])
//                tmp[i++] = nums[cur1++];
//            else
//                tmp[i++] = nums[cur2++];
//        }
//        while (cur1 <= mid)
//        {
//            tmp[i++] = nums[cur1++];
//        }
//        while (cur2 <= right)
//        {
//            tmp[i++] = nums[cur2++];
//        }
//
//        //tmp数组更新到nums数组中
//        for (int x = left; x <=right; x++)
//        {
//            nums[x] = tmp[x];
//        }
//        return ans;
//    }
//};

//升序（已通过）
class Solution {
    int tmp[50001];
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
    int mergeSort(vector<int>& nums, int left, int right)
    {
        if (left == right)
            return 0;
        int ans = 0;
        int mid = (left + right) >> 1;
        ans += mergeSort(nums, left, mid);
        ans += mergeSort(nums, mid + 1, right);

        int cur1 = left, cur2 = mid + 1;

        //统计翻转对
        while (cur2 <= right)
        {
            while (cur1 <= mid && nums[cur1] / 2.0 <= nums[cur2])
            {
                cur1++;
            }

            //right为数组最后位置的下标，而非元素个数
            if (cur1 > mid)
                break;
            else
            {
                ans += mid - cur1 + 1;
                cur2++;
            }
        }

        //归并排序（升序）
        cur1 = left, cur2 = mid + 1;
        int i = left;
        while (cur1 <= mid && cur2 <= right)
        {
            if (nums[cur1] <= nums[cur2])
                tmp[i++] = nums[cur1++];
            else
                tmp[i++] = nums[cur2++];
        }
        while (cur1 <= mid)
        {
            tmp[i++] = nums[cur1++];
        }
        while (cur2 <= right)
        {
            tmp[i++] = nums[cur2++];
        }

        //tmp数组更新到nums数组中
        for (int x = left; x <= right; x++)
        {
            nums[x] = tmp[x];
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = { 1,3,2,3,1 };
    Solution s;
    cout<<s.reversePairs(nums);
    return 0;
}