/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution
{
public:
    void bfs(int row, int col, int m, int n, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == '1' && vis[nrow][ncol] == 0)
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && vis[i][j] == 0)
                {
                    cnt++;

                    bfs(i, j, m, n, vis, grid);
                }
            }
        }
        return cnt;
    }
};
// @lc code=end
