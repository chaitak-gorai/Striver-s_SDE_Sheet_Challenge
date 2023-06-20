#include <bits/stdc++.h>
using namespace std;

void insert(int hp[], int n)
{

    int i = n;
    int temp = hp[i];
    while (i > 1 && temp > hp[i / 2])
    {
        hp[i] = hp[i / 2];
        i = i / 2;
    }
    hp[i] = temp;
}
void del(int hp[], int n)
{
    int temp = hp[1];
    int last = n;
    hp[1] = hp[last];
    int i = 1, j = 2 * i;
    while (j < last - 1)
    {
        if (hp[j + 1] > hp[j])
        {
            j = j + 1;
        }
        if (hp[i] < hp[j])
        {
            swap(hp[i], hp[j]);
            i = j;
            j = 2 * j;
        }
        else
        {
            break;
        }
    }
    hp[last] = temp;
}

int main()
{
    int hp[] = {-1,
                1,
                75,
                5,
                8,
                15,
                20,
                90};
    int n = 2;
    // for (int i = 2; i <= 7; i++)
    // {
    //     insert(hp, i);
    // }
    for (int i = 1; i <= 7; i++)
    {
        insert(hp, i);
    }
    for (int i = 7; i > 1; i--)
    {
        del(hp, i);
    }
    // insert(hp, n, 40);
    // insert(hp, n, 20);
    // insert(hp, n, 60);
    // del(hp, n);

    for (auto it : hp)
    {
        cout << it << " ";
    }
    return -1;
}