#include <bits/stdc++.h>
using namespace std;
class LockingTree
{
public:
    unordered_map<int, vector<int>> desc;
    vector<vector<int>> TreeNode;
    int n;
    LockingTree(vector<int> &parent)
    {
        n = parent.size();
        TreeNode.resize(n, vector<int>(2, -1));
        TreeNode[0][0] = -1;
        for (int i = 1; i < n; i++)
        {
            TreeNode[i][0] = parent[i];
            desc[parent[i]].push_back(i);
        }
    }

    bool lock(int num, int user)
    {
        if (TreeNode[num][1] == -1)
        {
            TreeNode[num][1] = user;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool unlock(int num, int user)
    {
        if (TreeNode[num][1] == user)
        {
            TreeNode[num][1] = -1;
            return true;
        }
        return false;
    }
    void checkDesc(int num, bool &atleastOne)
    {
        if (desc.count(num) == 0 || desc[num].size() == 0)
            return;
        for (auto it : desc[num])
        {
            if (TreeNode[it][1] != -1)
            {
                atleastOne = true;
                return;
            }
            else
            {
                checkDesc(it, atleastOne);
            }
        }
    }
    bool checkAnc(int num)
    {
        if (num == -1)
            return false;
        return TreeNode[num][1] != -1 || checkAnc(TreeNode[num][0]);
    }
    void unlockDesc(int num)
    {
        if (desc.count(num) == 0 || desc[num].size() == 0)
            return;
        for (auto it : desc[num])
        {
            TreeNode[it][1] = -1;
            unlockDesc(it);
        }
    }
    bool upgrade(int num, int user)
    {
        if (TreeNode[num][1] != -1)
            return false;
        bool atleastOne = false;
        checkDesc(num, atleastOne);
        if (atleastOne == false)
            return false;
        if (checkAnc(TreeNode[num][0]))
            return false;

        unlockDesc(num);
        TreeNode[num][1] = user;
        return true;
    }
};

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> parent(n, -1);
    unordered_map<string, int> nameToNum;
    string temp;
    cin >> temp;
    nameToNum[temp] = 0;
    for (int i = 1; i < n; i++)
    {
        string s;
        cin >> s;
        nameToNum[s] = i;
        parent[i] = (i - 1) / m;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << parent[i] << " ";
    // }
    // for (auto it = nameToNum.begin(); it != nameToNum.end(); it++)
    // {
    //     cout << it->first << " " << it->second << endl;
    // }
    LockingTree *tree = new LockingTree(parent);
    for (int i = 0; i < q; i++)
    {
        int op;
        string node;
        int userId;
        cin >> op >> node >> userId;
        if (op == 1)
        {
            if (tree->lock(nameToNum[node], userId))
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }
        else if (op == 2)
        {

            if (tree->unlock(nameToNum[node], userId))
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }
        else if (op == 3)
        {
            if (tree->upgrade(nameToNum[node], userId))
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }
    }
}
