/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        int len = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {

            len++;
            temp = temp->next;
        }
        if (len == 1 && n == 1)
        {
            return NULL;
        }
        if (len == n)
        {
            head = head->next;
            return head;
        }
        int cnt = 1;
        temp = head;
        while (cnt != len - n)
        {
            temp = temp->next;
            cnt++;
        }
        temp->next = temp->next->next;
        return head;
    }
};
// @lc code=end
