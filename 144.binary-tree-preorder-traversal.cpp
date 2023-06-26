/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void preorder(vector<int> &ans, TreeNode *root)
    {
        if (root == NULL)
            return;
        ans.push_back(root->val);
        preorder(ans, root->left);
        preorder(ans, root->right);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        // preorder(ans, root);
        stack<TreeNode *> stk;
        if (root == NULL)
            return ans;
        stk.push(root);
        while (!stk.empty())
        {
            TreeNode *node = stk.top();
            stk.pop();
            ans.push_back(node->val);
            if (node->right)
                stk.push(node->right);
            if (node->left)
                stk.push(node->left);
        }
        return ans;
    }
};
// @lc code=end
