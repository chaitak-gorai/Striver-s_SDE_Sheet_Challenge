/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *temp = head;
        unordered_map<ListNode *, int> mpp;
        while (temp != NULL)
        {
            if (mpp.find(temp) != mpp.end())
            {
                return true;
            }
            mpp[temp] = 1;
            temp = temp->next;
        }
        return false;
    }
};
// @lc code=end
