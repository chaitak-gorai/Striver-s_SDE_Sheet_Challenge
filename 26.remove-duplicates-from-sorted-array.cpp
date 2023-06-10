/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0;
        int j = 1;
        if (n == 1)
            return n;
        while (i < n && j < n)
        {
            if (nums[i] != nums[j])
            {
                nums[i + 1] = nums[j];
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return i + 1;
    }
};
// @lc code=end
