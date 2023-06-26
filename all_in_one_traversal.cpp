#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here.
    stack<pair<BinaryTreeNode<int> *, int>> stk;
    stk.push({root, 1});
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    vector<int> inorder;
    vector<int> preorder;
    vector<int> postorder;
    while (!stk.empty())
    {
        BinaryTreeNode<int> *node = stk.top().first;
        int num = stk.top().second;
        stk.pop();
        if (num == 1)
        {
            preorder.push_back(node->data);
            stk.push({node, num + 1});
            if (node->left)
                stk.push({node->left, 1});
        }
        else if (num == 2)
        {
            inorder.push_back(node->data);
            stk.push({node, num + 1});
            if (node->right)
                stk.push({node->right, 1});
        }
        else if (num == 3)
        {
            postorder.push_back(node->data);
        }
    }
    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);
    return ans;
}