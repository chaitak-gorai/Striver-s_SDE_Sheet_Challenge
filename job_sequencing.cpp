class Solution
{
public:
    static bool comparator(Job j1, Job j2)
    {
        if (j1.profit > j2.profit)
            return true;
        else
            return false;
    }
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        // your code here
        int md = 0;
        for (int i = 0; i < n; i++)
        {
            md = max(md, arr[i].dead);
        }
        vector<int> hm(md + 1, -1);
        sort(arr, arr + n, comparator);

        int maxi = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead; j > 0; j--)
            {
                if (hm[j] == -1)
                {
                    hm[j] = arr[i].id;
                    maxi += arr[i].profit;
                    cnt++;
                    break;
                }
            }
        }
        return {cnt, maxi};
    }
};