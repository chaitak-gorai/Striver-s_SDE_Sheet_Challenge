class MyStack
{
    queue<int> q1;
    queue<int> q2;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        if (!q1.empty())
        {
            q1.push(x);
        }
        else
        {
            if (!q2.empty())
            {
                q2.push(x);
            }
            else
            {
                q1.push(x);
            }
        }
    }

    int pop()
    {
        if (!q1.empty())
        {
            int count = q1.size() - 1;
            int res = q1.back();
            while (count--)
            {
                q2.push(q1.front());
                q1.pop();
            }
            q1.pop();
            return res;
        }
        else
        {
            if (q2.empty())
            {
                return 0;
            }
            else
            {
                int count = q2.size() - 1;
                int res = q2.back();
                while (count--)
                {
                    q1.push(q2.front());
                    q2.pop();
                }
                q2.pop();
                return res;
            }
        }
        return 0;
    }

    int top()
    {
        if (!q1.empty())
        {
            return q1.back();
        }
        else
        {
            if (!q2.empty())
            {
                return q2.back();
            }
            else
            {
                return 0;
            }
        }
    }

    bool empty()
    {
        if (q2.empty() && q1.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */