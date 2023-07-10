//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int fun(vector<int> &nums, vector<vector<int>> &dp, int ind, int last)
    {
        if (ind == 0)
        {
            if (nums[ind] < nums[last])
            {
                return nums[ind];
            }
            return 0;
        }
        if (dp[ind][last] != -1)
            return dp[ind][last];
        int pic = INT_MIN, npic;
        if (nums[ind] < nums[last])
        {
            pic = nums[ind] + fun(nums, dp, ind - 1, ind);
        }
        npic = fun(nums, dp, ind - 1, last);
        return dp[ind][last] = max(pic, npic);
    }
    int maxSumIS(int arr[], int n)
    {
        // Your code goes here
        vector<int> nums;
        for (int i = 0; i < n; i++)
        {
            nums.push_back(arr[i]);
        }
        int m = nums.size() - 1;

        vector<vector<int>> dp(m + 2, vector<int>(m + 2, -1));
        nums.push_back(INT_MAX);
        return fun(nums, dp, m, m + 1);
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

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.maxSumIS(a, n) << "\n";
    }
    return 0;
}

// } Driver Code Ends