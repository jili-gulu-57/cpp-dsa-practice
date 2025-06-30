#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


 //515.在每个树行中找最大值
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size())
        {
            //控制每层的循环
            int sz = q.size();
            int tmp = INT_MIN;
            for (int i = 0; i < sz; i++)
            {
                TreeNode* t = q.front();
                int v = t->val;
                tmp = max(tmp, v);
                q.pop();
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};