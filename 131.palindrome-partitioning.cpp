/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution
{
public:
    bool isPallindrome(string s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
            {
                return false;
            }
        }
        return true;
    }
    void f(int ind, string s, vector<string> &path, vector<vector<string>> &ans)
    {

        if (ind == s.size())
        {
            ans.push_back(path);
            return;
        }
        for (int i = ind; i < s.size(); i++)
        {
            if (isPallindrome(s, ind, i))
            {
                path.push_back(s.substr(ind, i - ind + 1));
                f(i + 1, s, path, ans);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> path;
        f(0, s, path, ans);
        return ans;
    }
};
// @lc code=end
