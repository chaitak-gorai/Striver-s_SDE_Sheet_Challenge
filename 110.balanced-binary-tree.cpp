/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    bool isBalanced(TreeNode *root)
    {
        if (balanced(root) == -1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    int balanced(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int lh = balanced(root->left);
        if (lh == -1)
            return -1;
        int rh = balanced(root->right);
        if (rh == -1)
            return -1;

        if (abs(lh - rh) > 1)
            return -1;

        return max(lh, rh) + 1;
    }
};
// @lc code=end
