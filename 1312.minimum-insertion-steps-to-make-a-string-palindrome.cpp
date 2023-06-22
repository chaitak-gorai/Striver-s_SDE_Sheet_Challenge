/*
 * @lc app=leetcode id=1312 lang=cpp
 *
 * [1312] Minimum Insertion Steps to Make a String Palindrome
 */

// @lc code=start
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int i1 = text1.size();
        int i2 = text2.size();
        vector<vector<int>> dp(i1 + 1, vector<int>(i2 + 1, -1));
        // return f(ind1-1,ind2-1, text1, text2,dp);
        for (int i = 0; i <= i1; i++)
        {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= i2; i++)
        {
            dp[0][i] = 0;
        }
        for (int ind1 = 1; ind1 <= i1; ind1++)
        {
            for (int ind2 = 1; ind2 <= i2; ind2++)
            {
                if (text1[ind1 - 1] == text2[ind2 - 1])
                {
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                }
                else
                {
                    dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
                }
            }
        }
        return dp[i1][i2];
    }
    int longestPalindromeSubseq(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());
        return longestCommonSubsequence(s, t);
    }
    int minInsertions(string s)
    {
        return s.size() - longestPalindromeSubseq(s);
    }
};
// @lc code=end
