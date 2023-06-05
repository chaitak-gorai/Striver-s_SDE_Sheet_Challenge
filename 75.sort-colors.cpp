/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int i0 = 0;
        int i1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                swap(nums[i0], nums[i]);
                i0++;
            }
        }
        i1 = i0;
        for (int i = i1; i < n; i++)
        {
            if (nums[i] == 1)
            {
                swap(nums[i1], nums[i]);
                i1++;
            }
        }
    }
};
// @lc code=end
