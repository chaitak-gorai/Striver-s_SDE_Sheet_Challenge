//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution
{
public:
    // Function to find minimum number of pages.
    bool isPossible(int A[], int N, int M, int tar)
    {
        int as = 1, pages = 0;
        for (int i = 0; i < N; i++)
        {
            if (A[i] > tar)
                return false;
            else if (pages + A[i] > tar)
            {
                as += 1;
                pages = A[i];
            }
            else
            {
                pages += A[i];
            }
        }
        if (as > M)
            return false;
        return true;
    }
    int findPages(int A[], int N, int M)
    {
        // code here
        if (M > N)
            return -1;
        int mini = INT_MIN;
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            mini = min(mini, A[i]);
            sum += A[i];
        }
        int l = mini, h = sum, res = INT_MAX;
        while (l <= h)
        {
            int mid = (l + h) >> 1;
            if (isPossible(A, N, M, mid))
            {
                res = min(res, mid);
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends