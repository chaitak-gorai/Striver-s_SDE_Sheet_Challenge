bool dfs(int node, int color, vector<int> &col, vector<vector<int>> &graph)
{
    col[node] = color;
    for (auto it : graph[node])
    {
        if (col[it] == -1)
        {
            if (dfs(it, !color, col, graph) == false)
            {
                return false;
            }
        }
        else if (col[it] == color)
        {
            return false;
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();

    vector<int> col(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (col[i] == -1)
        {
            if (bfs(i, col, graph) == false)
                return false;
        }
    }
    return true;
    ;
}