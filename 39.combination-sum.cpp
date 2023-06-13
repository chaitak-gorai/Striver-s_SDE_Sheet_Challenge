/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution
{
public:
    void f(vector<vector<int>> &ans, vector<int> &ds, int ind, int target, vector<int> &nums)
    {
        if (ind == nums.size())
        {
            if (target == 0)
            {
                ans.push_back(ds);
            }
            return;
        }
        if (nums[ind] <= target)
        {
            ds.push_back(nums[ind]);
            f(ans, ds, ind, target - nums[ind], nums);
            ds.pop_back();
        }

        f(ans, ds, ind + 1, target, nums);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        f(ans, ds, 0, target, candidates);
        return ans;
    }
};
// @lc code=end
