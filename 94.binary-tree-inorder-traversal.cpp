/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    void inorder(vector<int> &ans, TreeNode *root)
    {
        if (root == NULL)
            return;
        inorder(ans, root->left);
        ans.push_back(root->val);
        inorder(ans, root->right);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        // inorder(ans, root);
        stack<TreeNode *> stk;

        TreeNode *node = root;
        while (node != NULL || !stk.empty())
        {
            if (node != NULL)
            {
                stk.push(node);
                node = node->left;
            }
            else
            {
                if (stk.empty() == true)
                    break;
                node = stk.top();
                stk.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }
        return ans;
    }
};
// @lc code=end
