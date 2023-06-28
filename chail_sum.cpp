#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
// my-soultion (runtime error)
BinaryTreeNode<int> *Traversal(BinaryTreeNode<int> *root)
{
    if (root->left && root->right)
    {
        if (root->data > root->left->data + root->right->data)
        {
            root->left->data = root->data;
            root->right->data = root->data;
        }
    }
    else if (root->left != NULL && root->right == NULL)
    {
        if (root->data > root->left->data)
        {
            root->left->data = root->data;
        }
    }
    else
    {
        root->right->data = root->data;
    }
    if (root == NULL)
        return NULL;
    BinaryTreeNode<int> *left = Traversal(root->left);
    BinaryTreeNode<int> *right = Traversal(root->right);
    if (left && right)
        root->data = left->data + right->data;
    if (left != NULL && right == NULL)
        root->data = left->data;
    if (right != NULL && left == NULL)
        root->data = right->data;
    return root;
}

void changeTree(BinaryTreeNode<int> *root)
{
    // Write your code here.
    if (root == NULL)
        return;
    int child = 0;
    if (root->left)
        child += root->left->data;
    if (root->right)
        child += root->right->data;
    if (child >= root->data)
    {
        root->data = child;
    }
    else
    {
        if (root->left)
            root->left->data = root->data;
        if (root->right)
            root->right->data = root->data;
    }
    changeTree(root->left);
    changeTree(root->right);
    int tot = 0;
    if (root->left)
        tot += root->left->data;
    if (root->right)
        tot += root->right->data;
    if (root->left || root->right)
        root->data = tot;
}
