/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int cnt = 0;
        int el = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (cnt == 0)
            {
                el = nums[i];
            }
            if (el == nums[i])
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        return el;
    }
};
// @lc code=end
