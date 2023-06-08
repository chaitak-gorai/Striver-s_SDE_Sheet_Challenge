/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int car = 0;
        int sum = 0;
        int v = 0;
        ListNode *t1 = l1;
        ListNode *t2 = l2;
        ListNode *temp = NULL;
        ListNode *head = new ListNode(0);
        temp = head;
        while (t1 && t2)
        {
            sum = t1->val + t2->val + car;
            t1 = t1->next;
            t2 = t2->next;
            v = sum % 10;
            car = sum / 10;
            ListNode *node = new ListNode(v);
            temp->next = node;
            temp = node;
        }
        while (t1)
        {
            sum = t1->val + car;
            t1 = t1->next;
            v = sum % 10;
            car = sum / 10;
            ListNode *node = new ListNode(v);
            temp->next = node;
            temp = node;
        }
        while (t2)
        {
            sum = t2->val + car;
            t2 = t2->next;
            v = sum % 10;
            car = sum / 10;
            ListNode *node = new ListNode(v);
            temp->next = node;
            temp = node;
        }
        if (car)
        {
            ListNode *node = new ListNode(car);
            temp->next = node;
            temp = node;
        }
        temp->next = NULL;
        return head->next;
    }
};
// @lc code=end
