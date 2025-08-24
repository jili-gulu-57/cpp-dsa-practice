#include<iostream>
#include<stack>
#include<vector>
using namespace std;


//946.—È÷§’ª–Ú¡–
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int p1 = 0, p2 = 0;
        while (p1 < pushed.size())
        {
            s.push(pushed[p1++]);
            if (s.top() == popped[p2])
            {
                p2++;
                s.pop();
            }
        }
        if (s.empty())
            return true;
        return false;
    }
};

int main()
{
    vector<int> pushed = { 1,2,3,4,5 };
    vector<int> poped = { 4,5,3,2,1 };
    Solution s;
    s.validateStackSequences(pushed, poped);
    return 0;
}