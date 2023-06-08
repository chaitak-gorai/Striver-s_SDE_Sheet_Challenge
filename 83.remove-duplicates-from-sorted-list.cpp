/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *temp = head;
        while (temp != NULL)
        {

            ListNode *temp2 = temp->next;
            while (temp2 != NULL && temp2->val == temp->val)
            {
                temp2 = temp2->next;
            }
            temp->next = temp2;
            temp = temp->next;
        }
        return head;
    }
};
// @lc code=end
