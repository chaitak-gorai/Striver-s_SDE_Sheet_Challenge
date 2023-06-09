/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool check(TreeNode *r1, TreeNode *r2)
    {
        if (r1 == NULL || r2 == NULL)
            return r1 == r2;
        return r1->val == r2->val && check(r1->left, r2->right) && check(r1->right, r2->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        return check(root->left, root->right);
    }
};
// @lc code=end
