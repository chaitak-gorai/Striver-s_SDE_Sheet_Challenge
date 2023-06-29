/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
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
    bool findTarget(TreeNode *root, int k)
    {
        vector<int> inorder;
        inord(root, inorder);
        int l = 0, r = inorder.size() - 1;
        while (l < r)
        {
            if (inorder[l] + inorder[r] == k)
                return true;
            else if (inorder[l] + inorder[r] < k)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return false;
    }
};
// @lc code=end
