/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // map<int, int> hm;
        // for (auto it : nums)
        // {
        //     if (hm[nums[i]] == hm.end())
        //     {
        //         hm[nums[i]] = 1;
        //     }
        // }
        int n = nums.size();
        if (n == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int maxi = 1;
        int count = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
                continue;
            if (nums[i] + 1 == nums[i + 1])
            {
                count++;
                maxi = max(count, maxi);
            }
            else
            {
                count = 1;
            }
        }
        return maxi;
    }
};
// @lc code=end
