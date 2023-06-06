/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 */

// @lc code=start
class Solution
{
public:
    int count = 0;
    void merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
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
        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
    }
    void countPairs(vector<int> &arr, int low, int mid, int high)
    {
        int right = mid + 1;

        for (int i = low; i <= mid; i++)
        {

            while (right <= high && arr[i] > (long long)2 * arr[right])
            {
                right++;
            }
            count = count + (right - mid - 1);
        }
    }
    void mSort(vector<int> &arr, int low, int high)
    {
        if (low >= high)
            return;
        int mid = (low + high) / 2;
        mSort(arr, low, mid);
        mSort(arr, mid + 1, high);
        countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);
    }
    int reversePairs(vector<int> &nums)
    {
        mSort(nums, 0, nums.size() - 1);
        return count;
    }
};
// @lc code=end
