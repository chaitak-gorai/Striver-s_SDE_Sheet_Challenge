/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums2.size();
        unordered_map<int, int> mp;
        stack<int> s;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s.empty())
            {
                mp[nums2[i]] = -1;
            }
            else
            {
                while (s.size() > 0 && s.top() <= nums2[i])
                {
                    s.pop();
                }
                if (s.empty())
                {
                    mp[nums2[i]] = -1;
                }
                else
                {
                    mp[nums2[i]] = s.top();
                }
            }
            s.push(nums2[i]);
        }
        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++)
        {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};
// @lc code=end
