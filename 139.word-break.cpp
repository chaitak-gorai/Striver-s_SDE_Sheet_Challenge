/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution
{
public:
    bool solve(int ind, int n, string s, vector<string> &wordDict, vector<int> &dp)
    {
        if (ind == n)
        {
            return true;
        }
        if (dp[ind] != -1)
            return dp[ind];
        for (int i = ind; i < n; i++)
        {
            string sub = s.substr(ind, i - ind + 1);
            if (find(wordDict.begin(), wordDict.end(), sub) != wordDict.end())
            {
                if (solve(i + 1, n, s, wordDict, dp))
                {
                    return dp[ind] = 1;
                }
            }
        }
        return dp[ind] = 0;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<int> dp(s.size() + 1, -1);
        return solve(0, s.size(), s, wordDict, dp);
    }
};
// @lc code=end
