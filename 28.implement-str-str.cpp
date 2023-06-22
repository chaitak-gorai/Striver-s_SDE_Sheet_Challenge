class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        // int h = haystack.size();
        // int n = needle.size();
        // int flag = 0;

        // for (int i = 0; i < h; i++)
        // {
        //     if (haystack[i] == needle[0])
        //     {
        //         for (int j = 0; j < n; j++)
        //         {
        //             if (haystack[i + j] != needle[j])
        //             {
        //                 flag = 0;
        //                 break;
        //             }
        //             flag = 1;
        //         }
        //         if (flag == 1)
        //             return i;
        //     }
        // }
        // return -1;
        int h = haystack.size();
        int n = needle.size();
        string concat = needle + "$" + haystack;
        int s = concat.size();
        vector<int> Z(s, 0);
        int flag = 0;

        int l, r, k;
        l = r = 0;
        for (int i = 1; i < s; i++)
        {
            if (i > r)
            {
                l = r = i;
                while (r < s && concat[r - l] == concat[r])
                {
                    r++;
                }
                Z[i] = r - l;
                r--;
            }
            else
            {
                k = i - l;
                if (Z[k] < r - i + 1)
                {
                    Z[i] = Z[k];
                }
                else
                {
                    l = i;
                    while (r < s && concat[r - l] == concat[r])
                    {
                        r++;
                    }
                    Z[i] = r - l;
                    r--;
                }
            }
        }
        for (int i = 0; i < s; i++)
        {
            if (Z[i] == n)
            {
                return i - n - 1;
            }
            cout << Z[i];
        }
        return -1;
    }
};