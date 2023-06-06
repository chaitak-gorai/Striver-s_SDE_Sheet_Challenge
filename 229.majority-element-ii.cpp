/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> h;
        vector<int> ans;
        int limit = floor(nums.size() / 3);
        for (int i = 0; i < nums.size(); i++)
        {
            if (h[nums[i]])
            {
                h[nums[i]]++;
            }
            else
            {
                h[nums[i]] = 1;
            }
            if (h[nums[i]] == limit + 1)
            {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
// @lc code=end
