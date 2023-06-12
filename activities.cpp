#include <bits/stdc++.h>
struct meeting
{
    int start;
    int end;
    int pos;
};
static bool comparator(meeting m1, meeting m2)
{
    if (m1.end < m2.end)
        return true;
    else if (m1.end > m2.end)
        return false;
    else if (m1.pos < m2.pos)
        return true;
    return false;
}
int maximumActivities(vector<int> &start, vector<int> &end)
{
    // Write your code here.
    int n = start.size();
    struct meeting meet[n];
    for (int i = 0; i < n; i++)
    {
        meet[i].start = start[i];
        meet[i].end = end[i];
        meet[i].pos = i;
    }
    sort(meet, meet + n, comparator);
    int count = 1;
    int limit = meet[0].end;
    for (int i = 1; i < n; i++)
    {
        if (meet[i].start >= limit)
        {

            count++;
            limit = meet[i].end;
        }
    }
    return count;
}