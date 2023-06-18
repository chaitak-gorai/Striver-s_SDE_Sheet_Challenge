/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution
{
public:
    int myAtoi(string s)
    {
        int len = s.size();
        int i = 0;
        long long res = 0;
        int sign = 1;
        while (i < len && s[i] == ' ')
        {
            i++;
        }
        if (s[i] == '+')
        {
            sign = 1;
            i++;
        }
        else if (s[i] == '-')
        {
            sign = -1;
            i++;
        }
        int j = i;
        while (isdigit(s[j]))
        {
            j++;
        }
        j--;
        int k = 0;
        while (i <= j)
        {

            int d = int(s[i]) - 48;

            res = res * 10 + d;
            if (res > INT_MAX)
                break;

            i++;
        }

        res = res * sign;
        if (res > INT_MAX)
            return INT_MAX;
        if (res < INT_MIN)
            return INT_MIN;
        return res;
    }
};
// @lc code=end
