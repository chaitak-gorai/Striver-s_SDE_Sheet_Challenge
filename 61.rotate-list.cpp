/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL)
            return NULL;
        ListNode *temp = head;
        int len = 0;
        while (temp->next != NULL)
        {
            len++;
            temp = temp->next;
        }
        temp->next = head;
        temp = head;
        len++;
        k = k % len;
        int tar = len - k;
        while (tar - 1)
        {
            temp = temp->next;
            tar--;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};
// @lc code=end
