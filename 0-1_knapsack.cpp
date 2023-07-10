//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int f(int w, int W, int ind, int wt[], int val[], vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (w + wt[ind] <= W)
            {
                return val[ind];
            }
            else
            {
                return 0;
            }
        }
        if (dp[ind][w] != -1)
            return dp[ind][w];
        int pic = INT_MIN;
        if (w + wt[ind] <= W)
        {
            pic = val[ind] + f(w + wt[ind], W, ind - 1, wt, val, dp);
        }

        int npic = f(w, W, ind - 1, wt, val, dp);
        return dp[ind][w] = max(pic, npic);
    }

    int knapSack(int W, int wt[], int val[], int n)
    {
        // Your code here
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return f(0, W, n - 1, wt, val, dp);
    }
};

//{ Driver Code Starts.

int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // reading number of elements and weight
        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];

        // inserting the values
        for (int i = 0; i < n; i++)
            cin >> val[i];

        // inserting the weights
        for (int i = 0; i < n; i++)
            cin >> wt[i];
        Solution ob;
        // calling method knapSack()
        cout << ob.knapSack(w, wt, val, n) << endl;
    }
    return 0;
}
// } Driver Code Ends