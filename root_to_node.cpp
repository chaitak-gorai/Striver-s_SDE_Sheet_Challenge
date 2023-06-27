#include <bits/stdc++.h>
/*
    template <typename T = int>
    class TreeNode
    {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if (left != NULL)
            {
                delete left;
            }
            if (right != NULL)
            {
                delete right;
            }
        }
    };
*/

bool find(vector<int> &ans, TreeNode<int> *root, int tar)
{
    if (root == NULL)
        return false;
    if (root->data != tar)
        ans.push_back(root->data);
    else
        return true;
    bool l = find(ans, root->left, tar);
    bool r = find(ans, root->right, tar);
    if (l == false && r == false)
        ans.pop_back();
    return l || r;
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
    vector<int> ans;
    find(ans, root, x);
    ans.push_back(x);
    return ans;
}
