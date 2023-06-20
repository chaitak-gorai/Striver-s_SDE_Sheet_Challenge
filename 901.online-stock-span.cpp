/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

// @lc code=start
class StockSpanner
{
public:
    stack<pair<int, int>> stk;

    int cnt = 0;
    StockSpanner()
    {
    }

    int next(int price)
    {

        int ans;
        if (stk.empty())
        {
            ans = 1;
        }
        else
        {

            while (stk.size() > 0 && stk.top().first <= price)
            {

                stk.pop();
            }
            if (stk.empty())
            {
                ans = cnt + 1;
            }
            else
            {
                ans = cnt - stk.top().second;
            }
        }
        stk.push({price, cnt});
        cnt++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end
