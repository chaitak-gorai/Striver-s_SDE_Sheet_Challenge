class Solution
{
public:
    void dfs(int node, int &maxi, vector<int> &vis, vector<int> &pvis, vector<int> &edges, vector<int> &ans)
    {
        vis[node] = 1;
        pvis[node] = 1;
        ans.push_back(node);

        int it = edges[node];
        if (it != -1)
        {
            if (!vis[it])
            {
                dfs(it, maxi, vis, pvis, edges, ans);
            }
            else if (pvis[it])
            {
                int cnt = 0;
                int i = 0;
                cnt = ans.end() - find(ans.begin(), ans.end(), it);

                cout << cnt << " ";
                maxi = max(cnt, maxi);
            }
        }

        remove(ans.begin(), ans.end(), node);
        pvis[node] = 0;
    }
    int longestCycle(vector<int> &edges)
    {
        int n = edges.size();
        vector<int> vis(n, 0);
        vector<int> pvis(n, 0);
        vector<int> ans;
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {

            if (!vis[i])
            {
                dfs(i, maxi, vis, pvis, edges, ans);
            }
        }
        if (maxi < 0)
            return -1;
        return maxi;
    }
};