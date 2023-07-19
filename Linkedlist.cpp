#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int num)
    {
        this->data = num;
        this->next = NULL;
    }
};

Node *insert(Node *root, int data, int pos)
{
    Node *newn = new Node(data);
    if (pos == 0)
    {
        newn->next = root;

        root = newn;
        return root;
    }
    Node *temp = root;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    if (pos > len)
        return root;
    temp = root;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    newn->next = temp->next;
    temp->next = newn;
    return root;
}

Node *reverse(Node *root)
{
    Node *node = root;
    Node *prev = NULL;
    while (node != NULL)
    {
        Node *temp = node->next;
        node->next = prev;
        prev = node;
        node = temp;
    }
    return prev;
}
Node *deleteNode(Node *root, int pos)
{

    if (pos == 1)
        return root->next;
    Node *temp = root;
    Node *prev = NULL;
    for (int i = 1; i < pos; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    return root;
}
int main()
{
    int n;
    cin >> n;
    Node *root = new Node(0);
    Node *temp = root;
    while (n--)
    {
        int val;
        cin >> val;
        Node *node = new Node(val);
        temp->next = node;
        temp = node;
    }
    root = root->next;

    // root = insert(root, 5, 3);

    // root = reverse(root);
    root = deleteNode(root, 3);
    temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
