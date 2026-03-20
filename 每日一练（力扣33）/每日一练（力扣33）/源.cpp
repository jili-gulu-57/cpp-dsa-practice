#include<iostream>
#include<vector>
using namespace std;

//33.搜索旋转排序数组（已通过）
class Solution {
    int t;
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 1)
        {
            if (nums[0] == target)
                return 0;
            else
                return -1;
        }

        //二分找到左旋位置
        int a = n - 1;
        if (nums[n - 1] < nums[0])
            a = BinaryFind(nums, 0, n - 1);

        //二分查找target
        t = target;
        if (nums[0] <= t && nums[a - 1] >= t)
            return BinarySearch(nums, 0, a - 1);
        else
            return BinarySearch(nums, a, n - 1);
    }

    int BinaryFind(vector<int>& nums, int l, int r)
    {
        if (nums[r] >= nums[l])
            return l;
        int mid = (r + l) / 2;
        if (nums[mid] < nums[l])
        {
           return BinaryFind(nums, l, mid);
        }
        else
        {
           return BinaryFind(nums, mid + 1, r);
        }
    }

    int BinarySearch(vector<int>& nums, int l, int r)
    {
        if (l > r)
            return -1;
        int m = l + (r - l) / 2;  // 防止溢出
        if (nums[m] == t)
            return m;
        else
        {
            if (nums[m] > t)
            {
                return BinarySearch(nums, l, m - 1);
            }
            else
            {
                return BinarySearch(nums, m + 1, r);
            }
        }
    }
};

////测试二分查找代码
//int t = 23;
//int BinarySearch(vector<int>& nums, int l, int r)
//{
//    if (l > r)
//        return -1;
//    int m = l + (r - l) / 2;  // 防止溢出
//    if (nums[m] == t)
//        return m;
//    else
//    {
//        if (nums[m] > t)
//        {
//            return BinarySearch(nums, l, m - 1);
//        }
//        else
//        {
//            return BinarySearch(nums, m + 1, r);
//        }
//    }
//}

int main()
{
    //vector<int> nums = { 3,5,7,8,9,10,12,1,2 };
    vector<int> nums = {1};
    Solution s;
    cout << s.search(nums, 3);

    //vector<int> nums = { 3,5,7,8,9,10,12 };
    //cout << BinarySearch(nums, 0, 6);

    return 0;
}

//class Solution {
//    int t;
//public:
//    int search(vector<int>& nums, int target) {
//        t = target;
//        int n = nums.size(), ans = -1;
//        int begin = 0, end = n - 1;
//        while (begin < end)
//        {
//            int mid = (end + begin) / 2;
//            //左子区间有序
//            if (nums[mid] > nums[begin])
//            {
//                //并且在t在该范围内
//                if (nums[mid] >= t && nums[begin] <= t)
//                    return BinarySearch(nums, begin, mid);
//
//                //t在无序的右子区间
//                mid = (end + mid) / 2;
//
//            }
//            else  //右子区间有序
//            {
//                //并且t在该范围内
//                if (nums[mid + 1] <= t && nums[end] >= t)
//                    return BinarySearch(nums, mid + 1, end);
//
//                //t在无序的左子区间
//
//            }
//        }
//        return ans;
//    }
//
//    int BinarySearch(vector<int>& nums,int l,int r)
//    {
//        while (l < r)
//        {
//            if (nums[l] == t)
//                return l;
//            if (nums[r] == t)
//                return r;
//            if (l == r && nums[l] != t)
//                return -1;
//            else
//            {
//                int m = (r + l) / 2;
//                if(nums[m]>=t)
//                {
//                    BinarySearch(nums, l, m);
//                }
//                else
//                {
//                    BinarySearch(nums, m + 1, r);
//                }
//            }
//        }
//    }
//};