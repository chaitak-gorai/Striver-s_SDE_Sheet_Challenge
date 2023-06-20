/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder
{
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (maxheap.empty() && minheap.empty())
        {
            maxheap.push(num);
        }
        else
        {
            if (num > maxheap.top())
            {
                minheap.push(num);
            }
            else
            {
                maxheap.push(num);
            }
        }
        int n = maxheap.size();
        int m = minheap.size();
        if (n - m == 2 || n - m == -2)
        {
            if (n > m)
            {
                int temp = maxheap.top();
                maxheap.pop();
                minheap.push(temp);
            }
            else
            {
                int temp = minheap.top();
                minheap.pop();
                maxheap.push(temp);
            }
        }
    }

    double findMedian()
    {
        int n = maxheap.size();
        int m = minheap.size();
        if ((n + m) % 2 == 0)
        {
            return (double)(minheap.top() + maxheap.top()) / (double)2.0;
        }
        else
        {
            if (n > m)
            {
                return maxheap.top();
            }
            else
            {
                return minheap.top();
            }
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
