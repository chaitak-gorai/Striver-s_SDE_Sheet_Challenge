/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution
{
public:
    int f(int row, int col, vector<vector<int>> &dp)
    {
        if (row == 0 && col == 0)
        {
            return 1;
        }
        if (row < 0 || col < 0)
        {
            return 0;
        }
        if (dp[row][col] != -1)
            return dp[row][col];
        int up = f(row - 1, col, dp);
        int left = f(row, col - 1, dp);
        return dp[row][col] = up + left;
    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[0][0] = 1;
                }
                else
                {

                    int up = 0;
                    int left = 0;
                    if (i > 0)
                    {
                        cout << "y";
                        up = dp[i - 1][j];
                    };
                    if (j > 0)
                    {
                        left = dp[i][j - 1];
                    };
                    dp[i][j] = up + left;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
// RECURSSION
//  int f(int row,int col){
//      if(row==0 && col==0){
//          return 1;
//      }
//      if(row<0 || col<0){
//          return 0;
//      }
//      int up=f(row-1,col);
//      int left=f(row,col-1);
//      return up+left;
//  }
//  int uniquePaths(int m, int n) {
//      return f(m-1,n-1);
//  }
// MEMOIZATION
//  int f(int row,int col,vector<vector<int>>&dp){
//      if(row==0 && col==0){
//          return 1;
//      }
//      if(row<0 || col<0){
//          return 0;
//      }
//      if(dp[row][col]!=-1)return dp[row][col];
//      int up=f(row-1,col,dp);
//      int left=f(row,col-1,dp);
//      return dp[row][col]=up+left;
//  }
//  int uniquePaths(int m, int n) {
//      vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
//      return f(m-1,n-1,dp);
//  }
// @lc code=end
