/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
            return NULL;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            vector<Node *> t;
            while (!q.empty())
            {
                t.push_back(q.front());
                q.pop();
            }
            cout << t.size();
            for (int i = 0; i < t.size() - 1; i++)
            {
                t[i]->next = t[i + 1];
                if (t[i]->left)
                    q.push(t[i]->left);
                if (t[i]->right)
                    q.push(t[i]->right);
            }
            int last = t.size() - 1;
            if (t[last]->left)
                q.push(t[last]->left);
            if (t[last]->right)
                q.push(t[last]->right);
            t[last]->next = NULL;
        }
        return root;
    }
};
// @lc code=end
