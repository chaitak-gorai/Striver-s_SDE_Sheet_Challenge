/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

// @lc code=start
class Solution
{
public:
    bool bfs(int node, vector<int> &col, vector<vector<int>> &graph)
    {
        col[node] = 0;
        queue<int> q;
        q.push(node);
        while (!q.empty())
        {
            int temp = q.front();

            q.pop();
            for (auto it : graph[temp])
            {
                if (col[it] == -1)
                {
                    col[it] = !col[temp];
                    q.push(it);
                }
                else if (col[it] == col[temp])
                {
                    return false;
                }
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
};
// @lc code=end
