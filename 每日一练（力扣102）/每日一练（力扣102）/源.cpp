#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//102.二叉树的层序遍历（已通过）
//使用队列
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (!root)
        {
            return ans;
        }

        vector<int> row;
        int num = 0;    //记录上一层有几个有效节点
        ans.push_back({root->val});
        q.push(root);
        while (q.size())
        {
            TreeNode* tmp = q.front();
            q.pop();
            if (tmp->left)
            {
                q.push(tmp->left);
                row.push_back(tmp->left->val);
            }
            num--;
            if (tmp->right)
            {
                q.push(tmp->right);
                row.push_back(tmp->right->val);
            }
            num--;
            if (row.size()&&num<=0)//当上一层节点全判断完才算一层，此时将结果添加到ans中
            {
                ans.push_back(row);
                num = row.size() * 2;//左右子树各需判断一次
                row.clear();
            }
        }
        return ans;
    }
};

int main()
{
    TreeNode* n1 = new TreeNode(5);
    TreeNode* n2 = new TreeNode(0);
    TreeNode* n3 = new TreeNode(-4);
    TreeNode* n4 = new TreeNode(-1);
    TreeNode* n5 = new TreeNode(-6);
    TreeNode* n6 = new TreeNode(-9);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n8 = new TreeNode(1);
    TreeNode* n9 = new TreeNode(3);
    TreeNode* n10 = new TreeNode(0);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n4->left = n7;
    n5->left = n8;
    n5->right = n9;
    n6->right = n10;

    Solution s;
    s.levelOrder(n1);
    return 0;
}