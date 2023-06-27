/*
 * @lc app=leetcode id=662 lang=cpp
 *
 * [662] Maximum Width of Binary Tree
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
    int widthOfBinaryTree(TreeNode *root)
    {
        queue<pair<TreeNode *, int>> q;
        int width = 0;
        if (root == NULL)
            return width;
        q.push({root, 0});
        while (!q.empty())
        {
            int size = q.size();
            int minn = q.front().second;
            cout << minn;
            int first, last;
            for (int i = 0; i < size; i++)
            {
                int curr = q.front().second - minn;
                cout << curr << " ";
                TreeNode *node = q.front().first;
                q.pop();

                if (i == 0)
                    first = curr;
                if (i == size - 1)
                    last = curr;
                if (node->left != NULL)
                    q.push({node->left, (long long)curr * 2 + 1});
                if (node->right != NULL)
                    q.push({node->right, (long long)curr * 2 + 2});

                width = max(width, last - first + 1);
            }
        }
        return width;
    }
};
// @lc code=end
