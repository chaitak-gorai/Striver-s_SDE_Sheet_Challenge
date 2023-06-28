/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode *buildSubTree(int inStart, int inEnd, vector<int> &inorder, int postStart, int postEnd, vector<int> &postorder, map<int, int> &hmap)
    {
        if (inStart > inEnd || postStart > postEnd)
            return NULL;
        TreeNode *root = new TreeNode(postorder[postEnd]);
        int inRoot = hmap[root->val];
        int numsRight = inEnd - inRoot;

        root->left = buildSubTree(inStart, inRoot - 1, inorder, postStart, postEnd - numsRight - 1, postorder, hmap);
        root->right = buildSubTree(inRoot + 1, inEnd, inorder, postEnd - numsRight, postEnd - 1, postorder, hmap);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        map<int, int> hmap;
        for (int i = 0; i < inorder.size(); i++)
        {
            hmap[inorder[i]] = i;
        }
        return buildSubTree(0, inorder.size() - 1, inorder, 0, postorder.size() - 1, postorder, hmap);
    }
};
// @lc code=end
