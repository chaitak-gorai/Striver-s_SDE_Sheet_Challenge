class MyQueue
{
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue()
    {
    }

    void push(int x)
    {

        s1.push(x);
    }

    int pop()
    {
        int res = 0;
        if (!s2.empty())
        {
            res = s2.top();
            s2.pop();
            return res;
        }
        else
        {
            if (!s1.empty())
            {
                while (!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
                res = s2.top();

                s2.pop();
                return res;
            }
            else
            {
                return 0;
            }
        }
        return 0;
    }

    int peek()
    {
        if (!s2.empty())
        {
            return s2.top();
        }
        else
        {
            if (!s1.empty())
            {
                int s = s1.size();

                while (s--)
                {
                    s2.push(s1.top());

                    s1.pop();
                }
                return s2.top();
            }
            else
            {
                return 0;
            }
        }
        return 0;
    }

    bool empty()
    {
        if (s1.empty() && s2.empty())
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
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */