/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        if (n == 0)
            return 0;
        unordered_map<char, int> mpp;

        int l = 0, r = 0;
        int maxi = INT_MIN;
        while (r < n)
        {
            if (mpp.find(s[r]) != mpp.end())
            {
                l = max(mpp[s[r]] + 1, l);
            }
            mpp[s[r]] = r;
            maxi = max(maxi, r - l + 1);
            r++;
        }
        return maxi;
    }
};
// @lc code=end
