/*
 * @lc app=leetcode id=1373 lang=cpp
 *
 * [1373] Maximum Sum BST in Binary Tree
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
    int maxi = 0;
    class NodeValue
    {
    public:
        int minNode, maxNode, sum;
        NodeValue(int minNode, int maxNode, int sum)
        {
            this->minNode = minNode;
            this->maxNode = maxNode;
            this->sum = sum;
        }
    };

    NodeValue
    ms(TreeNode *root)
    {
        if (root == NULL)
            return NodeValue(INT_MAX, INT_MIN, 0);
        NodeValue l = ms(root->left);
        NodeValue r = ms(root->right);

        if (root->val > l.maxNode && root->val < r.minNode)
        {
            int sm = l.sum + r.sum + root->val;
            maxi = max(maxi, sm);
            return NodeValue(min(root->val, l.minNode), max(root->val, r.maxNode), sm);
        }
        maxi = max(maxi, max(l.sum, r.sum));
        return NodeValue(INT_MIN, INT_MAX, max(l.sum, r.sum));
    }
    int maxSumBST(TreeNode *root)
    {
        int sm = ms(root).sum;

        return maxi;
    }
};
// @lc code=end
