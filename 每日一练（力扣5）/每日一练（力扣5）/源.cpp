#include<iostream>
#include<string>
using namespace std;

//5.最长回文子串（已通过）
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 1)
            return s;

        string ans;
        int l = 0, r = n - 1;
        while (l < n-1)
        {
            while (r>l && s[l] != s[r])
            {
                r--;
            }

            int pos1 = l, pos2 = r;
            while (pos1 < pos2 && s[pos1] == s[pos2])
            {
                pos1++;
                pos2--;
            }
            if (pos1 == pos2 || pos1 == pos2 + 1)
            {
                if ((r - l + 1) > ans.size())
                {
                    ans = s.substr(l, r - l + 1);
                }
                l++;
                r = n - 1;
            }
            else
            {
                r--;
            }
        }

        return ans;
    }
};

int main()
{
    Solution ss;
    cout << ss.longestPalindrome("aacabdkacaa") << endl;
    return 0;
}