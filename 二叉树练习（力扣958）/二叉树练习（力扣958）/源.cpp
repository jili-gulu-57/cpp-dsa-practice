#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
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

 //ÒÑÍ¨¹ý
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while (q.size())
        {
            TreeNode* tmp = q.front();
            q.pop();
            if (tmp == NULL)
                break;

            q.push(tmp->left);
            q.push(tmp->right);
        }
        while (q.size())
        {
            TreeNode* tmp = q.front();
            if (tmp != nullptr)
                return false;
            q.pop();
        }
        return true;
    }
};