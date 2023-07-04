class Solution
{
public:
    void ts(int node, vector<int> &vis, stack<int> &stk, vector<int> adj[])
    {
        vis[node] = 1;

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                ts(it, vis, stk, adj);
            }
        }
        stk.push(node);
    }
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // code here
        vector<int> vis(V, 0);
        vector<int> ans;
        stack<int> stk;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                ts(i, vis, stk, adj);
            }
        }
        while (stk.size())
        {
            int temp = stk.top();
            stk.pop();
            ans.push_back(temp);
        }
        return ans;
    }
};