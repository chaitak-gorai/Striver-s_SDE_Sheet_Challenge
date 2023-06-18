#include <bits/stdc++.h>
using namespace std;
int s[10];
int top = -1;
class Stk
{
public:
    void push(int num)
    {
        top += 1;
        s[top] = num;
        cout << num << " is added to stack";
    }
    int pop()
    {
        if (top == -1)
            return -1;
        else
        {
            int temp = s[top];
            top--;
            return temp;
        }
    }
    int tp()
    {
        return s[top];
    }
};
int main()
{

    Stk stk;
    stk.push(10);
    stk.push(15);
    cout << s[0] << s[1];
    cout << stk.pop();
}