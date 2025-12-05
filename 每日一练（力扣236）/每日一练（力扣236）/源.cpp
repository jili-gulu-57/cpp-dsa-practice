#include<iostream>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
//236.二叉树的最近公共祖先（已通过）
 class Solution {
 public:
     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

         return dfs(root, p, q);;
     }
     TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q)
     {
         //当为空或者为p，q时直接返回
         if (root == nullptr)
             return root;

         TreeNode* l = dfs(root->left, p, q);
         TreeNode* r = dfs(root->right, p, q);

         if (root == p || root == q || (l && r))
             return root;

         if (l)
             return l;
         if (r)
             return r;

         return nullptr;
     }
 };

int main() {
    // 构建第二个例子的树
    //         3
    //        / \
    //       5   1
    //      / \ / \
    //     6  2 0  8
    //       / \
    //      7   4

    // 创建所有节点
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node0 = new TreeNode(0);
    TreeNode* node8 = new TreeNode(8);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node4 = new TreeNode(4);

    // 构建树结构
    node3->left = node5;
    node3->right = node1;
    node5->left = node6;
    node5->right = node2;
    node1->left = node0;
    node1->right = node8;
    node2->left = node7;
    node2->right = node4;

    // 创建解决方案实例
    Solution solution;

    // 测试第二个例子：p=5, q=4
    TreeNode* result = solution.lowestCommonAncestor(node3, node5, node4);

    //// 输出结果
    //cout << "测试例子：" << endl;
    //cout << "树结构如上所示" << endl;
    //cout << "p = 5, q = 4" << endl;
    //cout << "最近公共祖先(LCA)应该是: 5" << endl;

    //if (result) {
    //    cout << "计算结果: " << result->val << endl;
    //    if (result->val == 5) {
    //        cout << " 测试通过！" << endl;
    //    }
    //    else {
    //        cout << " 测试失败！" << endl;
    //    }
    //}
    //else {
    //    cout << " 未找到最近公共祖先！" << endl;
    //}

    // 释放内存（在实际项目中推荐使用智能指针）
    delete node3;
    delete node5;
    delete node1;
    delete node6;
    delete node2;
    delete node0;
    delete node8;
    delete node7;
    delete node4;

    return 0;
}