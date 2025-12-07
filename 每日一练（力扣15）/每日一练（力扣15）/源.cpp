#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

//15.三数之和（已通过）
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        //1.先排序
        sort(nums.begin(), nums.end());

        int n = nums.size();

        //数组全是正数或全是负数时无答案
        if (nums[0] > 0 || nums[n - 1] < 0)
            return ans;

        int i = 0, left = 0, right = 0, sum = 0;
        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            left = i + 1;
            right = n - 1;
            while (left < right)
            {
                sum = nums[i] + nums[left] + nums[right];

                if (sum == 0)
                {
                    ans.push_back({ nums[i],nums[left],nums[right] });
                    int l = nums[left];
                    int r = nums[right];

                    while (left < right && nums[left] == l)
                        left++;

                    while (left < right && nums[right] == r)
                        right--;
                }

                if (sum < 0)
                    left++;

                if (sum > 0)
                    right--;
            }
        }
        return ans;
    }
};


//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        vector<vector<int>> ans;
//        int n = nums.size();
//        if (n < 3) return ans;
//
//        // 1. 排序
//        sort(nums.begin(), nums.end());
//
//        for (int i = 0; i < n - 2; i++) {
//            // 2. 去重：跳过重复的第一个数
//            if (i > 0 && nums[i] == nums[i - 1]) {
//                continue;
//            }
//
//            // 3. 优化：如果第一个数大于0，后面不可能和为0
//            if (nums[i] > 0) break;
//
//            int left = i + 1;
//            int right = n - 1;
//
//            while (left < right) {
//                int sum = nums[i] + nums[left] + nums[right];
//
//                if (sum == 0) {
//                    ans.push_back({ nums[i], nums[left], nums[right] });
//
//                    // 4. 关键：找到答案后，跳过所有重复的left和right
//                    // 记录当前值
//                    int leftVal = nums[left];
//                    int rightVal = nums[right];
//
//                    // 跳过所有重复的left
//                    while (left < right && nums[left] == leftVal) {
//                        left++;
//                    }
//
//                    // 跳过所有重复的right
//                    while (left < right && nums[right] == rightVal) {
//                        right--;
//                    }
//                }
//                else if (sum < 0) {
//                    left++;
//                }
//                else {
//                    right--;
//                }
//            }
//        }
//
//        return ans;
//    }
//};
int main()
{
    vector<int> nums = { 0,0,0,0 };
    Solution s;
    s.threeSum(nums);
    return 0;
}


