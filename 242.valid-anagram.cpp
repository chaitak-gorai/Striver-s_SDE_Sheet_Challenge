/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int len1 = s.size();
        int len2 = t.size();
        vector<int> m1(27);
        vector<int> m2(27);
        for (int i = 0; i < len1; i++)
        {
            int index = int(s[i]) - 96;
            if (m1[index] != 0)
            {
                m1[index]++;
            }
            else
            {
                m1[index] = 1;
            }
        }
        for (int i = 0; i < len2; i++)
        {
            int index2 = int(t[i]) - 96;
            if (m2[index2])
            {
                m2[index2]++;
            }
            else
            {
                m2[index2] = 1;
            }
        }
        for (int i = 1; i < 27; i++)
        {

            if (m1[i] != m2[i])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
