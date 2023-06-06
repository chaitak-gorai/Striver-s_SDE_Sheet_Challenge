// #include <bits/stdc++.h>
// long long getInversions(long long *arr, int n)
// {
//     // Write your code here.
//     long long count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i; j < n; j++)
//         {
//             if (i < j && arr[i] > arr[j])
//             {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

#include <bits/stdc++.h>
long long merge(long long *arr, long long low, long long mid, long long high)
{
    vector<long long> temp;
    long long left = low;
    long long right = mid + 1;
    long long count = 0;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            count += mid - left + 1;
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (long long i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
    return count;
}
long long mSort(long long *arr, int low, int high)
{
    long long count = 0;
    if (low >= high)
        return count;
    long long mid = (low + high) / 2;
    count += mSort(arr, low, mid);
    count += mSort(arr, mid + 1, high);
    count += merge(arr, low, mid, high);
    return count;
}
long long getInversions(long long *arr, int n)
{
    // Write your code here.
    return mSort(arr, 0, n - 1);
}