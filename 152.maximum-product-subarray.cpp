/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int prod = 1;
        bool zero = false;
        int lmax = nums[0];
        int rmax = nums[0];
        for (auto it : nums)
        {
            prod *= it;
            if (it == 0)
            {
                zero = true;
                prod = 1;
                continue;
            }
            lmax = max(lmax, prod);
        }
        prod = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            prod *= nums[i];
            if (nums[i] == 0)
            {
                prod = 1;
                zero = true;
                continue;
            }
            rmax = max(rmax, prod);
        }
        if (zero)
        {
            return max(max(lmax, rmax), 0);
        }
        else
            return max(lmax, rmax);
    }
};
// @lc code=end
