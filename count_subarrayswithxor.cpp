#include <bits/stdc++.h>

int subarraysXor(vector<int> &A, int x)
{
    //    Write your code here.
    // Write your code here
    map<long long, int> hp;
    long long xr = 0;
    hp[xr]++;
    int count = 0;
    for (int i = 0; i < A.size(); i++)
    {
        xr = xr ^ A[i];
        int k = xr ^ x;
        count += hp[k];
        hp[xr]++;
    }
    return count;
}