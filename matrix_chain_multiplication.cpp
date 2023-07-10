//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int f(int i, int j, int arr[], int mini, vector<vector<int>> &dp)
    {
        if (i == j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int steps;
        for (int k = i; k < j; k++)
        {
            steps = arr[i - 1] * arr[k] * arr[j] + f(i, k, arr, mini, dp) + f(k + 1, j, arr, mini, dp);
            mini = min(mini, steps);
        }

        return dp[i][j] = mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int>(N + 1, 0));
        // return f(1,N-1,arr,INT_MAX,dp);
        for (int i = 0; i < N; i++)
        {
            dp[i][i] = 0;
        }

        for (int i = N - 1; i >= 1; i--)
        {
            for (int j = i + 1; j < N; j++)
            {
                int steps;
                int mini = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                    mini = min(mini, steps);
                }

                dp[i][j] = mini;
            }
        }
        return dp[1][N - 1];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.matrixMultiplication(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends