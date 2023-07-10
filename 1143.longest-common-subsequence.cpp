/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution
{
public:
    int fun(string &s1, string &s2, vector<vector<int>> &dp, int ind1, int ind2)
    {
        if (ind1 == 0 || ind2 == 0)
        {
            if (ind1 == 0)
            {
                for (int i = ind2; i >= 0; i--)
                {
                    if (s1[ind1] == s2[i])
                    {
                        return 1;
                    }
                }
                return 0;
            }
            else
            {
                for (int i = ind1; i >= 0; i--)
                {
                    if (s1[i] == s2[ind2])
                    {
                        return 1;
                    }
                }
                return 0;
            }
        }
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        int pic = INT_MIN, npic1, npic2, npic3;
        if (s1[ind1] == s2[ind2])
        {
            pic = 1 + fun(s1, s2, dp, ind1 - 1, ind2 - 1);
        }
        npic1 = fun(s1, s2, dp, ind1, ind2 - 1);
        npic2 = fun(s1, s2, dp, ind1 - 1, ind2);
        npic3 = fun(s1, s2, dp, ind1 - 1, ind2 - 1);
        return dp[ind1][ind2] = max(max(pic, npic1), max(npic2, npic3));
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return fun(text1, text2, dp, n - 1, m - 1);
    }
};
// @lc code=end
