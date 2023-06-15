//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int kthElement(int nums1[], int nums2[], int n1, int n2, int k)
    {
        if (n2 < n1)
            return kthElement(nums2, nums1, n2, n1, k);

        int l = max(0, k - n2), h = min(k, n1);
        while (l <= h)
        {
            int c1 = (l + h) >> 1;
            int c2 = k - c1;

            int l1 = c1 == 0 ? INT_MIN : nums1[c1 - 1];
            int l2 = c2 == 0 ? INT_MIN : nums2[c2 - 1];

            int r1 = c1 == n1 ? INT_MAX : nums1[c1];
            int r2 = c2 == n2 ? INT_MAX : nums2[c2];

            if (l1 <= r2 && l2 <= r1)
            {

                return max(l1, l2);
            }
            else if (l1 > r2)
            {
                h = c1 - 1;
            }
            else
            {
                l = c1 + 1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int arr1[n], arr2[m];
        for (int i = 0; i < n; i++)
            cin >> arr1[i];
        for (int i = 0; i < m; i++)
            cin >> arr2[i];

        Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k) << endl;
    }
    return 0;
}
// } Driver Code Ends