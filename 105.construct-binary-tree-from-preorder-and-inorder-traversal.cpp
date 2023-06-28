/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode *buildSubTree(int preStart, int preEnd, vector<int> &preorder, int inStart, int inEnd, vector<int> &inorder, map<int, int> &hmap)
    {
        if (preStart > preEnd || inStart > inEnd)
            return NULL;
        TreeNode *root = new TreeNode(preorder[preStart]);
        int inRoot = hmap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildSubTree(preStart + 1, preStart + numsLeft, preorder, inStart, inRoot - 1, inorder, hmap);
        root->right = buildSubTree(preStart + numsLeft + 1, preEnd, preorder, inRoot + 1, inEnd, inorder, hmap);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        map<int, int> hmap;
        for (int i = 0; i < inorder.size(); i++)
        {
            hmap[inorder[i]] = i;
        }
        return buildSubTree(0, preorder.size() - 1, preorder, 0, inorder.size() - 1, inorder, hmap);
    }
};
// @lc code=end
