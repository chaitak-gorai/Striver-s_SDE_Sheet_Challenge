/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> stk;
        int maxA = 0;
        //         vector<int>nsl;
        //         vector<int>nsr;
        int n = heights.size();
        //         for(int i=0;i<n;i++){
        //          if(stk.empty()){
        //              nsl.push_back(-1);

        //          }else{
        //              while(stk.size()>0 && heights[stk.top()]>=heights[i]){
        //                  stk.pop();
        //              }
        //              if(stk.empty()){
        //                  nsl.push_back(-1);
        //              }else{
        //                  nsl.push_back(stk.top());
        //              }

        //          }
        //             stk.push(i);
        //         }
        //          stack<int>stk2;
        //                 for(int i=n-1;i>=0;i--){
        //          if(stk2.empty()){
        //              nsr.push_back(n);

        //          }else{
        //              while(stk2.size()>0 && heights[stk2.top()]>=heights[i]){
        //                  stk2.pop();
        //              }
        //              if(stk2.empty()){
        //                  nsr.push_back(n);
        //              }else{
        //                  nsr.push_back(stk2.top());
        //              }

        //          }
        //             stk2.push(i);
        //         }
        //         reverse(nsr.begin(),nsr.end());
        //         for(int i=0;i<n;i++){
        //             int area=(nsr[i]-nsl[i]-1)*heights[i];
        //             cout<<nsl[i]<<" ";
        //              maxA=max(maxA,area);
        //         }
        for (int i = 0; i <= n; i++)
        {
            while (!stk.empty() && (i == n || heights[stk.top()] > heights[i]))
            {
                int height = heights[stk.top()];
                stk.pop();
                int width;
                if (stk.empty())
                    width = i;
                else
                    width = i - stk.top() - 1;
                maxA = max(maxA, width * height);
            }
            stk.push(i);
        }
        return maxA;
    }
};
// @lc code=end
