/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> ind(numCourses, 0);
        for (auto it : prerequisites)
        {
            ind[it[0]]++;
        }
        queue<int> q;
        vector<int> topo;
        for (int i = 0; i < numCourses; i++)
        {
            if (ind[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int temp = q.front();
            topo.push_back(q.front());
            q.pop();
            for (auto it : prerequisites)
            {
                if (it[1] == temp)
                {
                    ind[it[0]]--;
                    if (ind[it[0]] == 0)
                    {
                        q.push(it[0]);
                    }
                }
            }
        }
        if (topo.size() != numCourses)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
// @lc code=end
