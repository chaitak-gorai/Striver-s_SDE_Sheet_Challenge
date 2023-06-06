#include <bits/stdc++.h>

pair<int, int> missingAndRepeating(vector<int> &A, int n)
{
    // Write your code here
    vector<int> hash(A.size() + 1, 0);
    for (int i = 0; i < A.size(); i++)
    {
        hash[A[i]]++;
    }
    pair<int, int> ans;
    int repeated = 0, missing = 0;
    for (int i = 1; i <= A.size(); i++)
    {
        if (hash[i] > 1)
        {
            repeated = i;
        }
        if (hash[i] == 0)
        {
            missing = i;
        }
    }
    if (repeated != 0)
    {
        ans.second = repeated;
    }
    if (missing != 0)
    {
        ans.first = missing;
    }

    return ans;
}
