#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//已通过
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        if (root == nullptr)
            return ans;

        int level = 1;
        q.push(root);

        while (q.size())
        {
            int s = q.size();
            vector<int> path;
            for (int i = 0; i < s; i++)
            {
                TreeNode* tmp = q.front();
                path.push_back(tmp->val);
                q.pop();
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
            }
            //偶数层先逆序
            if (level % 2 == 0)
                reverse(path.begin(), path.end());
            ans.push_back(path);
            level++;
        }
        return ans;
    }
};