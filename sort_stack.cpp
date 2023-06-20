#include <bits/stdc++.h>
void insert(stack<int> &stk, int temp)
{
    if (stk.size() == 0 || stk.top() <= temp)
    {
        stk.push(temp);
        return;
    }
    int temp2 = stk.top();
    stk.pop();
    insert(stk, temp);
    stk.push(temp2);
    return;
}
void sortStk(stack<int> &stack)
{
    if (stack.size() == 1)
    {
        return;
    }
    int temp = stack.top();
    stack.pop();
    sortStk(stack);
    insert(stack, temp);
    return;
}
void sortStack(stack<int> &stack)
{
    // Write your code here
    sortStk(stack);
}