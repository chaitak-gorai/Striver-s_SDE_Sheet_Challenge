/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution
{
public:
    int fun(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (row == 0 && col == 0)
        {
            return grid[row][col];
        }

        if (row < 0 || col < 0)
            return 1e8;
        if (dp[row][col] != -1)
            return dp[row][col];
        int left = grid[row][col] + fun(row, col - 1, grid, dp);
        int up = grid[row][col] + fun(row - 1, col, grid, dp);
        return dp[row][col] = min(left, up);
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return fun(n - 1, m - 1, grid, dp);
    }
};
// @lc code=end
