//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int countSmaller(vector<int> &r, int tar)
    {
        int l = 0, h = r.size() - 1;
        while (l <= h)
        {
            int mid = (l + h) >> 1;
            if (r[mid] <= tar)
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
        return l;
    }
    int median(vector<vector<int>> &matrix, int R, int C)
    {
        // code here
        int low = 1;
        int high = 2001;
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            int cnt = 0;
            for (int row = 0; row < R; row++)
            {
                cnt += countSmaller(matrix[row], mid);
            }
            if (cnt <= (R * C) / 2)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        int ans = -1;
        ans = obj.median(matrix, r, c);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends