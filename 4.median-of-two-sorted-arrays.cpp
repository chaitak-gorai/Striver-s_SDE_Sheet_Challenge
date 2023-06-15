/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution
{
public:
    int countSmaller(vector<int> &nums, int target)
    {
        int l = 0, h = nums.size() - 1;
        while (l <= h)
        {
            int mid = (l + h) >> 1;
            if (nums[mid] <= target)
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
        return l;
    }
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // int n = nums1.size();
        // int m = nums2.size();
        // int low = 0;
        // int high = 1e7;
        // while (low <= high)
        // {
        //     int mid = (low + high) >> 1;
        //     int cnt = 0;
        //     cnt += countSmaller(nums1, mid);
        //     cnt += countSmaller(nums2, mid);
        //     if (cnt <= (n + m) / 2)
        //     {
        //         low = mid + 1;
        //     }
        //     else
        //     {
        //         high = mid - 1;
        //     }
        // }
        // if (n == m)
        //     return (low) / (double)2;
        // return low;
        if (nums2.size() < nums1.size())
            return findMedianSortedArrays(nums2, nums1);

        int n1 = nums1.size();
        int n2 = nums2.size();
        int l = 0, h = n1;
        while (l <= h)
        {
            int c1 = (l + h) >> 1;
            int c2 = (n1 + n2 + 1) / 2 - c1;

            int l1 = c1 == 0 ? INT_MIN : nums1[c1 - 1];
            int l2 = c2 == 0 ? INT_MIN : nums2[c2 - 1];

            int r1 = c1 == n1 ? INT_MAX : nums1[c1];
            int r2 = c2 == n2 ? INT_MAX : nums2[c2];

            if (l1 <= r2 && l2 <= r1)
            {
                if ((n1 + n2) % 2 == 0)
                {
                    return (max(l1, l2) + min(r1, r2)) / (double)2;
                }
                else
                {
                    return max(l1, l2);
                }
            }
            else if (l1 > r2)
            {
                h = c1 - 1;
            }
            else
            {
                l = c1 + 1;
            }
        }
        return -1;
    }
};
// @lc code=end
