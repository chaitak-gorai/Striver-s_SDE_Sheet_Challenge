#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x)
{
    // Write your code here.
    int ceil = INT_MAX;
    BinaryTreeNode<int> *temp = node;
    while (temp != NULL)
    {
        if (temp->data >= x)
        {
            ceil = min(ceil, temp->data);
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    if (ceil == INT_MAX)
        return -1;
    return ceil;
}