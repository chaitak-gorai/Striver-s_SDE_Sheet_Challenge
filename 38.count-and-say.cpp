/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution
{
public:
    string say(string &res, int n, int limit)
    {
        if (n == limit + 1)
        {
            return res;
        }
        string s = "11";
        if (n == 1)
            return say(s, n + 1, limit);
        cout << res << " ";
        int cnt = 1;
        string temp = "";
        for (int i = 0; i < res.size() - 1; i++)
        {
            if (res[i] == res[i + 1])
            {
                cnt++;
            }
            else
            {
                temp = cnt + res[i];
                cout << temp << "*";
                res.replace(res[i - cnt + 1], res[i], temp);
                cnt = 1;
            }
        }
        return say(res, n + 1, limit);
    }
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        if (n == 2)
            return "11";
        string res = "11";
        for (int j = 3; j <= n; j++)
        {
            int cnt = 1;
            string temp = "";
            res = res + "$";
            for (int i = 1; i < res.size(); i++)
            {
                if (res[i] == res[i - 1])
                {
                    cnt++;
                }
                else
                {
                    temp = temp + to_string(cnt) + res[i - 1];

                    cnt = 1;
                }
            }
            res = temp;
        }
        return res;
    }
};
// @lc code=end
