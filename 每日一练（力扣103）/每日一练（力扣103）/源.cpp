#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

//103.二叉树的锯齿形层序遍历（已通过）
//正序遍历，最后将数组逆置
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
        if (!root)
            return ans;

        vector<int> onelevel;
        onelevel.push_back(root->val);
        ans.push_back(onelevel);
        onelevel.clear();
        queue<TreeNode*> q;
        q.push(root);
        int count = 0, num = 2;
        while (q.size())
        {
            TreeNode* tmp = q.front();
            q.pop();
            if (tmp->left)
            {
                onelevel.push_back(tmp->left->val);
                q.push(tmp->left);
            }
            count--;
            if (tmp->right)
            {
                onelevel.push_back(tmp->right->val);
                q.push(tmp->right);
            }
            count--;

            if (count <= 0)
            {
                if (num % 2 == 0)
                {
                    reverse(onelevel.begin(), onelevel.end());
                }
                ans.push_back(onelevel);
                count = onelevel.size() * 2;
                onelevel.clear();
                num++;
            }
        }
        ans.pop_back();
        return ans;
    }
};

int main()
{
    TreeNode* t1 = new TreeNode;
    TreeNode* t2 = new TreeNode;
    TreeNode* t3 = new TreeNode;
    TreeNode* t4 = new TreeNode;
    TreeNode* t5 = new TreeNode;
    TreeNode* t6 = new TreeNode;
    TreeNode* t7 = new TreeNode;
    TreeNode* t8 = new TreeNode;
    TreeNode* t9 = new TreeNode;
    TreeNode* t10 = new TreeNode;

    t1->val = 0;
    t2->val = -4;
    t3->val = -3;
    t4->val = -1;
    t5->val = 8;
    t6->val = 3;
    t7->val = 9;
    t8->val = -2;
    t9->val = 4;
    t10->val = 8;

    t1->left = t2;
    t1->right = t3;
    t2->right = t4;
    t3->left = t5;
    t4->right = t6;
    t5->right = t7;
    t6->left = t8;
    t7->left = t9;
    //t6->right = t10;

    Solution s;
    s.zigzagLevelOrder(t1);
    return 0;
}