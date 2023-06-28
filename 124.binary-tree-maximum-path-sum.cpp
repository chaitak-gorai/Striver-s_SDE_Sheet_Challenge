/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int maxi = INT_MIN;
    int maxP(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int lh = max(0, maxP(root->left));
        int rh = max(0, maxP(root->right));
        maxi = max(lh + rh + root->val, maxi);
        return max(lh, rh) + root->val;
    }
    int maxPathSum(TreeNode *root)
    {

        maxP(root);
        return maxi;
    }
};
// @lc code=end
