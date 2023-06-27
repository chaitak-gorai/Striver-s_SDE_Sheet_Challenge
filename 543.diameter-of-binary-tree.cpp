/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int maxh = 0;
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        height(root);
        return maxh;
    }
    int height(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        if (lh + rh >= maxh)
            maxh = lh + rh;
        return 1 + max(lh, rh);
    }
};
// @lc code=end
