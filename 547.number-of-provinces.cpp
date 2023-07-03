/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class Solution
{
public:
    void dfs(int node, vector<int> adj[], vector<int> &vis)
    {
        for (auto it : adj[node])
        {
            if (vis[it] == -1)
            {
                vis[it] = 1;
                dfs(it, adj, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> vis(n, -1);
        vector<int> adj[n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j && isConnected[i][j] == 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == -1)
            {
                ans++;
                dfs(i, adj, vis);
            }
        }
        return ans;
    }
};
// @lc code=end
