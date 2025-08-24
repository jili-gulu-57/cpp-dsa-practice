#include<iostream>
#include<stack>
#include<vector>
using namespace std;


//946.验证栈序列（已通过）
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int p1 = 0, p2 = 0, flag = 0;
        while (p2 < pushed.size())
        {
            if (p1 < pushed.size())
            {
                s.push(pushed[p1++]);
                flag = 1;
            }
            while (p2<popped.size()&&s.size()&&s.top() == popped[p2])
            {
                p2++;
                s.pop();
                flag = 1;
            }
            if (flag == 0)
                return false;
            flag = 0;
        }

        return true;
    }
};

int main()
{
    vector<int> pushed = { 1,0 };
    vector<int> poped = { 1,0 };
    Solution s;
    s.validateStackSequences(pushed, poped);
    return 0;
}