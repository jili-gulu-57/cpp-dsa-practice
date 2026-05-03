#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//199.二叉树的右视图（已通过）
//题目理解：每层只返回最右的节点
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root)  //为空直接返回
            return ans;
        ans.push_back(root->val);
        queue<TreeNode*> q;
        q.push(root);
        int count = 2;
        vector<int> nums;
        //层序遍历，只要最右侧一个节点
        while (q.size())
        {
            TreeNode* tmp = q.front();
            q.pop();
            if (tmp->left)
            {
                q.push(tmp->left);
                nums.push_back(tmp->left->val);
            }
            count--;
            if (tmp->right)
            {
                q.push(tmp->right);
                nums.push_back(tmp->right->val);
            }
            count--;
            if(count<=0)
            {
                count = nums.size() * 2;
                if(nums.size())
                {
                    ans.push_back(nums.back());
                    nums.clear();
                }
            }
        }
        return ans;
    }
};

TreeNode* buildTree(const vector<int>& nums) {
    if (nums.empty() || nums[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nums.size()) {
        TreeNode* cur = q.front();
        q.pop();

        // 左孩子
        if (i < nums.size() && nums[i] != -1) {
            cur->left = new TreeNode(nums[i]);
            q.push(cur->left);
        }
        i++;

        // 右孩子
        if (i < nums.size() && nums[i] != -1) {
            cur->right = new TreeNode(nums[i]);
            q.push(cur->right);
        }
        i++;
    }

    return root;
}

int main()
{
    vector<int> nums = { 1,2,3,4,5,-1,6,7,-1,-1,-1,8 };
    Solution s;
    vector<int> ans=s.rightSideView(buildTree(nums));
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}