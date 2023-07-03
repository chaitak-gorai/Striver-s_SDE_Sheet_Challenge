bool dfs(int node, int parent, vector<int> &vis, vector<int> adj[])
{
    bool ans = false;
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            vis[it] = 1;
            ans = dfs(it, node, vis, adj);
        }
        else if (it != parent)
        {
            return true;
        }
    }
    return ans;
}
bool isCycle(int V, vector<int> adj[])
{
    // Code here
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            bool ans = dfs(i, -1, vis, adj);
            if (ans == true)
                return true;
        }
    }
    return false;
}