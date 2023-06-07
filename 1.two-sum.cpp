/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = i + 1; j < n; j++)
        //     {
        //         if (nums[i] + nums[j] == target)
        //         {
        //             return {i, j};
        //         }
        //     }
        // }
        // return {};

        unordered_map<int, int> hm;
        for (int i = 0; i < n; i++)
        {
            hm[nums[i]] = i;
        }
        for (int i = 0; i < n; i++)
        {
            if (find(nums.begin(), nums.end(), target - nums[i]) != nums.end())
            {
                if (i != hm[target - nums[i]])
                {
                    return {i, hm[target - nums[i]]};
                }
            }
        }
        return {};
    }
};
// @lc code=end
