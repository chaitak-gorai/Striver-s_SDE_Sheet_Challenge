#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_func(string s)
{
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
        {
            j = pi[j - 1];
        }
        if (s[i] == s[j])
        {
            j++;
            pi[i] = j;
        }
    }
    return pi;
}
int main()
{
    string str = "ABABDABACDABABCABAB";
    string s = "ABABCABAB";

    vector<int> lps = prefix_func(s);
    lps.insert(lps.begin(), 0);

    int j = 0, i = 0;
    while (j < s.size() && i < str.size())
    {
        if (str[i] == s[j + 1])
        {
            j++;
            i++;
        }
        else
        {

            if (j == 0)
            {

                i++;
            }
            else
            {
                j = lps[j];
            }
        }
        if (j == s.size() - 1)
        {
            printf("Found pattern at index %d ", i - j - 1);
            j = lps[j - 1];
        }
    }
    return -1;
}
