/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution
{
public:
    int fun(vector<int> &nums, vector<vector<int>> &dp, int ind, int last)
    {
        if (ind == 0)
        {
            if (nums[ind] < nums[last])
            {
                return 1;
            }
            return 0;
        }
        if (dp[ind][last] != -1)
            return dp[ind][last];
        int pic = INT_MIN, npic;
        if (nums[ind] < nums[last])
        {
            pic = 1 + fun(nums, dp, ind - 1, ind);
        }
        npic = fun(nums, dp, ind - 1, last);
        return dp[ind][last] = max(pic, npic);
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size() - 1;
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        nums.push_back(INT_MAX);
        return fun(nums, dp, n, n + 1);
    }
};
// @lc code=end
