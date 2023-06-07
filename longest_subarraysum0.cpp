#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector<int> A)
{

    // Write your code here
    map<long long, int> hp;
    long long sum = 0;
    int len = 0;
    for (int i = 0; i < A.size(); i++)
    {
        sum += A[i];
        if (sum == 0)
        {
            len = max(len, i + 1);
        }
        long long rem = sum - 0;
        ;
        if (hp.find(rem) != hp.end())
        {
            len = max(len, i - hp[rem]);
        }
        if (hp.find(sum) == hp.end())
        {
            hp[sum] = i;
        }
    }
    return len;
}