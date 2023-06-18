/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution
{
public:
    int romanToInt(string s)
    {
        int prev = 0;
        int sum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'I')
            {
                sum += 1;
                prev = 1;
            }
            else if (s[i] == 'V')
            {
                if (prev == 1)
                {
                    sum += 3;
                }
                else
                {
                    sum += 5;
                }
                prev = 0;
            }
            else if (s[i] == 'X')
            {
                if (prev == 1)
                {
                    sum += 8;
                }
                else
                {
                    sum += 10;
                }
                prev = 10;
            }
            else if (s[i] == 'L')
            {
                if (prev == 10)
                {
                    sum += 30;
                }
                else
                {
                    sum += 50;
                }
                prev = 0;
            }
            else if (s[i] == 'C')
            {
                if (prev == 10)
                {
                    sum += 80;
                }
                else
                {
                    sum += 100;
                }
                prev = 100;
            }
            else if (s[i] == 'D')
            {
                if (prev == 100)
                {
                    sum += 300;
                }
                else
                {
                    sum += 500;
                }
                prev = 0;
            }
            else if (s[i] == 'M')
            {
                if (prev == 100)
                {
                    sum += 800;
                }
                else
                {
                    sum += 1000;
                }
                prev = 0;
            }
        }
        return sum;
    }
};
// @lc code=end
