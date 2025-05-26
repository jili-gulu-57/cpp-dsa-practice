#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
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
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* root)
    {
        if (root == nullptr)
            return;
        ans.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
};