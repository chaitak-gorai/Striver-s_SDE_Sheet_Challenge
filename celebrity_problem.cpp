//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    bool knows(vector<vector<int>> &M, int a, int b)
    {
        return M[a][b] == 0;
    }
    int celebrity(vector<vector<int>> &M, int n)
    {
        // code here
        stack<int> stk;
        for (int i = 0; i < n; i++)
        {
            stk.push(i);
        }
        while (stk.size() > 1)
        {
            int p1 = stk.top();

            stk.pop();
            int p2 = stk.top();

            stk.pop();
            if (knows(M, p1, p2))
            {
                stk.push(p1);
            }
            else if (knows(M, p2, p1))
            {
                stk.push(p2);
            }
        }
        int last = stk.top();

        for (int i = 0; i < n; i++)
        {
            if (M[last][i] == 1)
                return -1;
            if (i != last && M[i][last] == 0)
                return -1;
        }
        return last;
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
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
}

// } Driver Code Ends