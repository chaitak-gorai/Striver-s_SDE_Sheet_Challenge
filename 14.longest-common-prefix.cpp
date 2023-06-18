/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int len = strs.size();
        string res = "";
        int match = 0;
        for (int j = 0; j < strs[0].size(); j++)
        {
            char flag = strs[0][j];
            for (int i = 0; i < len; i++)
            {
                if (strs[i][j] != flag)
                {
                    return res;
                    match = 1;
                }
            }
            if (match == 0)
            {
                res += flag;
            }
        }
        return res;
    }
};
// @lc code=end
