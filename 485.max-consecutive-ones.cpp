/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 */

// @lc code=start
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int maxi = 0;
        int cnt = 0;
        int n = nums.size();
        for (auto it : nums)
        {
            if (it == 1)
            {
                cnt++;
                maxi = max(maxi, cnt);
            }
            else
            {
                cnt = 0;
            }
        }
        return maxi;
    }
};
// @lc code=end
