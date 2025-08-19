#include<iostream>
#include<vector>
using namespace std;

//LCR 170.交易逆序对的总数（已通过）
class Solution {
    int tmp[50010];
public:
    int mergesort(vector<int>& record, int left, int right)
    {
        if (left >= right)
            return 0;

        int mid = (left + right) >> 1;
        int ans = 0;

        ans += mergesort(record, left, mid);
        ans += mergesort(record, mid + 1, right);

        int begin1 = left, begin2 = mid + 1, i = 0;
        while (begin1 <= mid && begin2 <= right)
        {
            if (record[begin1] <= record[begin2])
                tmp[i++] = record[begin1++];
            else
            {
                ans += mid - begin1 + 1;
                tmp[i++] = record[begin2++];
            }
        }
        while (begin1 <= mid)
            tmp[i++] = record[begin1++];
        while (begin2 <= right)
            tmp[i++] = record[begin2++];

        for (int i = left; i <= right; i++)
            record[i] = tmp[i - left];

        return ans;
    }
    int reversePairs(vector<int>& record)
    {
        return mergesort(record, 0, record.size() - 1);
    }
};

int main()
{
    Solution s;
    vector<int> v;
    s.reversePairs(v);
    return 0;
}