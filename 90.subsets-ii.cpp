/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution
{
public:
    void ss(vector<vector<int>> &ans, vector<int> &ds, vector<int> &nums, int ind)
    {
        ans.push_back(ds);
        for (int i = ind; i < nums.size(); i++)
        {
            if (i != ind && nums[i] == nums[i - 1])
                continue;
            ds.push_back(nums[i]);
            ss(ans, ds, nums, i + 1);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;

        vector<int> ds;
        sort(nums.begin(), nums.end());
        ss(ans, ds, nums, 0);
        return ans;
    }
};
// @lc code=end
