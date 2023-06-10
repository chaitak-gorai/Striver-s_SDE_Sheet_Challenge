/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
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
    ListNode *detectCycle(ListNode *head)
    {
        unordered_map<ListNode *, int> mpp;
        ListNode *temp = head;
        while (temp != NULL)
        {
            if (mpp.find(temp) != mpp.end())
                return temp;
            mpp[temp] = 1;
            temp = temp->next;
        }
        return NULL;
    }
};
// @lc code=end
