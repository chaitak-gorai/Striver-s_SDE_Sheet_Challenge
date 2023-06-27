/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    void rv(vector<int> &ans, int level, TreeNode *root)
    {
        if (root == NULL)
            return;
        if (level == ans.size())
            ans.push_back(root->val);
        rv(ans, level + 1, root->right);
        rv(ans, level + 1, root->left);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        rv(ans, 0, root);
        return ans;
    }
};
// @lc code=end
