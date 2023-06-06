/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1.0;
        long long nn = n;
        if (n < 0)
        {
            nn = -1 * nn;
        }
        while (nn)
        {
            if (nn % 2 == 0)
            {
                x = x * x;
                nn = nn / 2;
            }
            else
            {
                ans = ans * x;
                nn = nn - 1;
            }
        }
        if (n < 0)
        {
            return (double)1.0 / ans;
        }
        else
        {
            return ans;
        }
    }
};
// @lc code=end
