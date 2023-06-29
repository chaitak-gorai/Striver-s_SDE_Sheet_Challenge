#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> *root, int X)
{
    // Write your code here.
    //
    TreeNode<int> *temp = root;
    int floor = -1;
    while (temp != NULL)
    {
        if (temp->val <= X)
        {
            floor = max(floor, temp->val);
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    return floor;
}