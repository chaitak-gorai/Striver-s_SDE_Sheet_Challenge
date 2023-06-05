/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int maxi = INT_MIN;
        int sum = 0;
        for (auto it : nums)
        {
            int temp = sum + it;
            maxi = max(temp, maxi);
            sum = max(temp, 0);
        }
        return maxi;
    }
};
// @lc code=end
