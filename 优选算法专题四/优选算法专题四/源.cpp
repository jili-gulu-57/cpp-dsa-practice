#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//226282 【模板】前缀和（牛客，已通过）
//int main() {
//	int n = 0, q = 0, l = 0, r = 0, i = 0;
//	cin >> n >> q;
//	vector<int> arr(n + 1,0);
//	//注意数据范围较大，因此使用long long
//	vector<long long> dp(n + 1, 0);
//	for (i = 1; i <= n; i++)
//	{
//		cin >> arr[i];
//	}
//	for (i = 1; i <= n; i++)
//	{
//		dp[i] = arr[i] + dp[i - 1];
//	}
//	while (q--)
//	{
//		cin >> l >> r;
//		cout << dp[r] - dp[l - 1] << endl;
//	}
//	return 0;
//}


//DP35.【模板】二维数组前缀和（已通过）
//#include <iostream>
//using namespace std;
//int main() {
//    int n, m, q, x1, y1, x2, y2, i, j;
//    cin >> n >> m >> q;
//    vector<vector<int>> nums(n+1, vector<int>(m+1,0));
//    vector<vector<long long>> dp(n+1, vector<long long>(m+1,0));
//    for(i=1;i<=n;i++)
//    {
//        for (j = 1; j <= m; j++)
//        {
//            cin >> nums[i][j];
//        }
//    }
//    //预处理
//    for (i = 1; i <= n; i++)
//    {
//        for (j = 1; j <= m; j++)
//        {
//            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + nums[i][j] - dp[i - 1][j - 1];
//        }
//    }
//    while (q--)
//    {
//        cin >> x1 >> y1 >> x2 >> y2;
//        cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] << endl;
//    }
//    return 0;
//}


//724.寻找数组的中心数组（已通过）
//class Solution {
//public:
//    int pivotIndex(vector<int>& nums) {
//        int m = nums.size(), i = 0;
//        //前缀和数组
//        vector<int> fsum(m);
//        //后缀和数组
//        vector<int> gsum(m);
//        for (i = 1; i < m; i++)
//        {
//            fsum[i] = nums[i - 1] + fsum[i - 1];
//        }
//        for (i = m - 2; i >= 0; i--)
//        {
//            gsum[i] = nums[i + 1] + gsum[i + 1];
//        }
//        for (i = 0; i < m; i++)
//        {
//            if (fsum[i] == gsum[i])
//                return i;
//        }
//        return -1;
//    }
//};


//238.除自身以外数组的乘积（已通过）
//class Solution {
//public:
//    vector<int> productExceptSelf(vector<int>& nums) {
//        int n = nums.size();
//        vector<int> f(n);
//        f[0] = nums[0];
//        vector<int> g(n);
//        g[n - 1] = nums[n - 1];
//        vector<int> ans(n);
//        //前缀积
//        for (int i = 1; i < n; i++)
//        {
//            f[i] = f[i - 1] * nums[i];
//        }
//        //后缀积
//        for (int i = n - 2; i >= 0; i--)
//        {
//            g[i] = g[i + 1] * nums[i];
//        }
//        for (int i = 1; i < n - 1; i++)
//        {
//            ans[i] = f[i - 1] * g[i + 1];
//        }
//        ans[0] = g[1];
//        ans[n - 1] = f[n - 2];
//        return ans;
//    }
//};
//int main()
//{
//    vector<int> nums = { 5,3,2,1 };
//    Solution s;
//    for (auto i : s.productExceptSelf(nums))
//    {
//        cout << i << " ";
//   }
//    return 0;
//}


//560.和为k的子数组（已通过）
//#include<unordered_map>
//class Solution {
//public:
//    int subarraySum(vector<int>& nums, int k) {
//        unordered_map<int, int> hash;
//        hash[0] = 1;
//        int sum = 0, ret = 0;
//        for (auto x : nums)
//        {
//            sum += x;
//            if (hash.count(sum - k))
//                ret += hash[sum - k];
//            hash[sum]++;
//        }
//        return ret;
//    }
//};
//int main()
//{
//    vector<int> nums = { 1,-1,0 };
//    Solution s;
//    cout<<s.subarraySum(nums, 0);
//    return 0;
//}
//class Solution {
//public:
//    int subarraySum(vector<int>& nums, int k) {
//        unordered_map<int, int> hash;
//        hash[0] = 1;
//        int sum = 0;
//        int ans = 0;
//        for (auto i : nums)
//        {
//            sum += i;
//            if (hash.count(sum - k))
//                ans += hash[sum - k];
//            hash[sum]++;
//        }
//        return ans;
//    }
//};
//int main()
//{
//    vector<int> nums = {1, -1, 0};
//    Solution s;
//    s.subarraySum(nums, 0);
//}


//974.和可被k整除的子数组（已通过）
//#include<unordered_map>
//class Solution {
//public:
//    int subarraysDivByK(vector<int>& nums, int k) {
//        unordered_map<int, int> hash;
//        hash[0 % k] = 1;
//        int sum = 0, ans = 0;
//        for (auto x : nums)
//        {
//            sum += x;
//            int yushu = (sum % k + k) % k;
//            if (hash.count(yushu))
//                ans += hash[yushu];
//            hash[yushu]++;
//        }
//        return ans;
//    }
//};
//int main()
//{
//    vector<int> nums = { 4,5,0,-2,-3,1 };
//    Solution s;
//    s.subarraysDivByK(nums, 5);
//    return 0;
//}


//525.连续数组（已通过）
//#include<unordered_map>
//class Solution {
//public:
//    int findMaxLength(vector<int>& nums) {
//        for (int i=0;i<nums.size();i++)
//        {
//            if (nums[i] == 0)
//                nums[i] = -1;
//        }
//        unordered_map<int, int> hash;
//        int sum = 0, ans = 0;
//        hash[0] = -1;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            sum += nums[i];
//            if (hash.count(sum))
//                ans = max(i - hash[sum], ans);
//            else
//                hash[sum] = i;
//        }
//        return ans;
//    }
//};
//int main()
//{
//    vector<int> nums = { 0,1 };
//    Solution s;
//    s.findMaxLength(nums);
//}


//1314.矩阵区域和（已通过）
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        //填表
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = mat[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            }
        }
        //映射到ans表中
        int x1, y1, x2, y2;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                x1 = max(1, i - k);
                y1 = max(1, j - k);
                x2 = min(m, i + k);
                y2 = min(n, j + k);
                ans[i - 1][j - 1] = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
            }
        }
        return ans;
    }
};
int main()
{
    vector<vector<int>> mat = { {1,2,3},{4,5,6},{7,8,9} };
    Solution s;
    s.matrixBlockSum(mat, 1);
    return 0;
}