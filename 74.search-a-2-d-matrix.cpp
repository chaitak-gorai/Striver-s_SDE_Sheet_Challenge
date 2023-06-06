/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution
{
public:
    bool ans = false;
    void searchRow(vector<int> row, int low, int high, int target)
    {
        int mid = (low + high) / 2;
        if (low == high)
        {
            if (row[mid] == target)
                ans = true;
            return;
        }

        if (row[mid] > target)
        {
            searchRow(row, low, mid, target);
        }
        else if (row[mid] < target)
        {
            searchRow(row, mid + 1, high, target);
        }
        else
        {
            ans = true;
        }
    }
    void ms(vector<vector<int>> &matrix, int low, int high, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int midr = (low + high) / 2;
        if (low == high)
        {
            cout << "yes";
            searchRow(matrix[midr], 0, n - 1, target);
            return;
        }

        if (target > matrix[midr][n - 1])
        {
            ms(matrix, midr + 1, high, target);
        }
        else if (target < matrix[midr][0])
        {
            ms(matrix, low, midr, target);
        }
        else
        {
            searchRow(matrix[midr], 0, n - 1, target);
        }
    }
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        ms(matrix, 0, m - 1, target);
        return ans;
    }
};
// @lc code=end
