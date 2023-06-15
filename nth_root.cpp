//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int f(int m, int n, int start, int end)
    {
        if (start > end)
            return -1;
        int mid = (start + end) / 2;

        if (pow(mid, n) == m)
            return mid;
        else if ((pow(mid, n)) < m)
            return f(m, n, mid + 1, end);
        else
            return f(m, n, start, mid - 1);
    }
    int NthRoot(int n, int m)
    {
        // Code here.
        return f(m, n, 1, m);
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.NthRoot(n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends