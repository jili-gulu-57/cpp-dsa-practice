#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;

        int left = maxdepth(root->left);
        int right = maxdepth(root->right);
        int n = abs(left - right);

        return n < 2 && isBalanced(root->left) && isBalanced(root->right);
    }
    int maxdepth(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        int left = maxdepth(root->left);
        int right = maxdepth(root->right);
        int m = max(left, right);
        return m + 1;
    }
};
int main()
{
    TreeNode* n1 = new TreeNode;
    TreeNode* n2 = new TreeNode;
    TreeNode* n3 = new TreeNode;
    TreeNode* n4 = new TreeNode;
    TreeNode* n5 = new TreeNode;
    n1->val = 1;
    n2->val = 2;
    n3->val = 3;
    n4->val = 4;
    n5->val = 5;

    n1->left = n2;
    n2->left = n4;
    n1->right = n3;
    n3->right = n5;
    n2->right = nullptr;
    n3->left = nullptr;
    n4->left = n4->right = nullptr;
    n5->left = n5->right = nullptr;
    Solution s;
    s.isBalanced(n1);
    return 0;
}