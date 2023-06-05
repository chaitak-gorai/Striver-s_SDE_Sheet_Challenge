/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        // int n = nums.size();
        // sort(nums.begin(), nums.end());
        // for (int i = 0; i < n - 1; i++)
        // {
        //     if (nums[i] == nums[i + 1])
        //     {
        //         return nums[i];
        //         break;
        //     }
        // }
        // return 0;
        int slow = nums[0];
        int fast = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        fast = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
// @lc code=end
