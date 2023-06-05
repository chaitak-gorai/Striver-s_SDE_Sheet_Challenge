/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int j = 0;
        for (int i = 1; i < n; i++)
        {
            int flag = 1;

            if (intervals[i][0] <= ans[j][1] && intervals[i][1] >= ans[j][0])
            {
                ans[j][1] = max(intervals[i][1], ans[j][1]);
                ans[j][0] = min(ans[j][0], intervals[i][0]);
            }
            else
            {
                ans.push_back(intervals[i]);
                j++;
            }
        }
        return ans;
    }
};
// @lc code=end
