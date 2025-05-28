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

class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int k = 0;
        while (q.size())
        {
            int count = pow(2, k);
            vector<int> level;
            while (count--)
            {
                if (q.empty())
                    return ans;
                TreeNode* tmp = q.front();
                if (tmp == nullptr)
                {
                    q.pop();
                    continue;
                }

                level.push_back(tmp->val);
                q.pop();
                q.push(tmp->left);
                q.push(tmp->right);
                
            }
            k++;
            if (level.size())
                ans.push_back(level);
        } 
        return ans;
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
    n2->left = n3;
    n3->left = n4;
    n4->left = n5;
    n1->right = nullptr;
    n2->right = nullptr;
    n3->right = nullptr;
    n4->right = nullptr;
   
    //n1->right = n3;
    //n3->left = n4;
    //n3->right = n5;
    //n2->left = n2->right = nullptr;
    //n4->left = n4->right = nullptr;
    n5->left = n5->right = nullptr;
    Solution s;
    s.levelOrder(n1);
    return 0;
}