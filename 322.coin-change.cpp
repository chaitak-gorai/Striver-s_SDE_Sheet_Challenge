/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution
{
public:
    int fun(int ind, int al, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (al == 0)
        {
            return 0;
        }
        if (ind == 0)
        {
            if (al % coins[ind] == 0)
            {
                return al / coins[ind];
            }
            else
            {
                return 1e8;
            }
        }
        if (dp[ind][al] != -1)
            return dp[ind][al];
        int pic = 1e8;
        if (coins[ind] <= al)
        {
            pic = 1 + fun(ind, al - coins[ind], coins, dp);
        }
        int npic = fun(ind - 1, al, coins, dp);
        return dp[ind][al] = min(pic, npic);
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = fun(n - 1, amount, coins, dp);
        if (ans == 1e8)
            return -1;
        return ans;
    }
};
// @lc code=end
