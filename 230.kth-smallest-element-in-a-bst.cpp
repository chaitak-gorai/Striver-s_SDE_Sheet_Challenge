/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    void inord(TreeNode *root, vector<int> &inorder)
    {
        if (root == NULL)
            return;
        inord(root->left, inorder);
        inorder.push_back(root->val);
        inord(root->right, inorder);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> inorder;
        inord(root, inorder);
        return inorder[k - 1];
    }
};
// @lc code=end
