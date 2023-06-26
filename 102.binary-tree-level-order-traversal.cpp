/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {

        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        while (!q.empty())
        {
            vector<int> temp;
            vector<TreeNode *> t;
            while (!q.empty())
            {
                t.push_back(q.front());
                q.pop();
            }
            for (auto it : t)
            {
                temp.push_back(it->val);
                if (it->left)
                    q.push(it->left);
                if (it->right)
                    q.push(it->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
// @lc code=end
