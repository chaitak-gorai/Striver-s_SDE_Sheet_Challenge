/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack
{
public:
    stack<long long> s;
    // stack<int> mn;
    long long me = INT_MAX;
    MinStack()
    {
    }

    void push(int val)
    {
        if (s.empty())
        {
            s.push(val);
            me = val;
        }
        else
        {
            if (val >= me)
            {
                s.push(val);
            }
            else
            {
                long long valu = val;
                valu = 2 * valu - me;
                s.push(valu);
                me = val;
            }
        }
    }

    void pop()
    {
        if (s.top() > me)
        {
            s.pop();
        }
        else
        {
            me = 2 * me - s.top();
            s.pop();
        }
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return (int)me;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
