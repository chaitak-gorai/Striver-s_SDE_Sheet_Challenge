/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (auto it : nums)
        {
            mp[it]++;
        }
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mnh;
        for (auto i = mp.begin(); i != mp.end(); i++)
        {
            mnh.push({i->second, i->first});
            if (mnh.size() > k)
            {
                mnh.pop();
            }
        }
        while (mnh.size())
        {
            ans.push_back(mnh.top().second);
            mnh.pop();
        }
        return ans;
    }
};
// @lc code=end
