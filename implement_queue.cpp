#include <bits/stdc++.h>
using namespace std;
int q[10];
int front = -1, rear = 0, cnt = 0;
class Q
{
public:
    void push(int num)
    {
        if (cnt == 10)
        {
            cout << "Queue is full";
            return;
        }

        q[rear % 10] = num;
        rear++;
        cout << num << " is added to stack";
    }
    int pop()
    {
        if (front == rear)
            return -1;
        else
        {
            int temp = q[front % 10];
            front++;
            cnt--;
            return temp;
        }
    }
    int top()
    {
        return s[front];
    }
};
int main()
{

    Stk stk;
    stk.push(10);
    cout << s[0];
}