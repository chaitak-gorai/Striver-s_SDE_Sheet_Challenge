/*
 * @lc app=leetcode id=1636 lang=cpp
 *
 * [1636] Sort Array by Increasing Frequency
 */

// @lc code=start
class Solution
{
public:
    static bool customComparator(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.first == b.first)
        {
            return a.second < b.second; // Sort in decreasing order based on second int
        }
        return a.first > b.first; // Sort based on first int
    }
    vector<int> frequencySort(vector<int> &nums)
    {
        map<int, int> mp;
        for (auto it : nums)
        {
            mp[it]++;
        }
        vector<int> ans;

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&customComparator)> mnh(&customComparator);
        for (auto i = mp.rbegin(); i != mp.rend(); ++i)
        {

            mnh.push({i->second, i->first});
        }
        while (mnh.size())
        {
            for (int i = 0; i < mnh.top().first; i++)
            {
                ans.push_back(mnh.top().second);
            }

            mnh.pop();
        }
        return ans;
    }
};
// @lc code=end
