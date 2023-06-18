/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> vs;
        string res = "";
        int i = 0;
        string temp = "";
        int len1 = s.size();
        for (i = 0; s[i] != '\0'; i++)
        {

            if (s[i] != ' ')
            {

                temp.push_back(s[i]);
            }
            else if (i != 0 && s[i] == ' ' && s[i - 1] != ' ')
            {
                vs.push_back(temp);
                temp = "";
            }
        }
        if (temp != "")
        {
            vs.push_back(temp);
        }
        for (string st : vs)
        {
            cout << st;
        }
        int len = vs.size();
        for (int j = len - 1; j >= 0; j--)
        {
            for (char c : vs[j])
            {
                res.push_back(c);
            }
            res.push_back(' ');
        }
        res.pop_back();

        return res;
    }
};
// @lc code=end
