//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find number of strongly connected components in the graph.
    void dfs(int node, stack<int> &stk, vector<int> &vis, vector<vector<int>> &adj)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, stk, vis, adj);
            }
        }
        stk.push(node);
    }
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        // code here
        stack<int> stk;
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, stk, vis, adj);
            }
        }
        vector<vector<int>> adjT(V);
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                adjT[it].push_back(i);
            }
        }
        vector<int> visT(V, 0);
        stack<int> temp;
        int cnt = 0;
        while (!stk.empty())
        {
            int node = stk.top();
            stk.pop();
            if (!visT[node])
            {
                dfs(node, temp, visT, adjT);
                cnt++;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends