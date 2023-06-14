/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution
{
public:
    void solve(int col, int n, vector<string> &board, vector<vector<string>> &ans, vector<int> &lrow, vector<int> &ld, vector<int> &ud)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (lrow[row] == 0 && ld[row + col] == 0 && ud[n - 1 + col - row] == 0)
            {
                board[row][col] = 'Q';
                lrow[row] = 1;
                ld[row + col] = 1;
                ud[n - 1 + col - row] = 1;
                solve(col + 1, n, board, ans, lrow, ld, ud);
                board[row][col] = '.';
                lrow[row] = 0;
                ld[row + col] = 0;
                ud[n - 1 + col - row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        vector<int> lrow(n, 0), ld(2 * n - 1, 0), ud(2 * n - 1, 0);
        solve(0, n, board, ans, lrow, ld, ud);
        return ans;
    }
};
// @lc code=end
