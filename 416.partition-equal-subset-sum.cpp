/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution
{
public:
    bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;
        if (ind == 0)
            return arr[0] == target;
        if (dp[ind][target] != -1)
        {
            if (dp[ind][target] == 1)
            {
                return true;
            }
            else if (dp[ind][target] == 0)
            {
                return false;
            }
        }
        bool not_take = f(ind - 1, target, arr, dp);
        bool take = false;
        if (arr[ind] <= target)
        {
            take = f(ind - 1, target - arr[ind], arr, dp);
        }
        if (take || not_take)
        {
            dp[ind][target] = 1;
        }
        else
        {
            dp[ind][target] = 0;
        }
        return take || not_take;
    }
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        for (auto it : nums)
        {
            sum += it;
        }
        if (sum % 2 != 0)
            return false;
        sum = sum / 2;

        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return f(n - 1, sum, nums, dp);
    }
};
// @lc code=end
