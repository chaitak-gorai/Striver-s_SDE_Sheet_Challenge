/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL && list2 == NULL)
        {
            return NULL;
        }
        else if (list1 == NULL)
        {
            return list2;
        }
        else if (list2 == NULL)
        {
            return list1;
        }
        ListNode *head = NULL;
        ListNode *t1, *t2;
        if (list1->val < list2->val)
        {
            head = list1;
            t1 = list1->next;
            t2 = list2;
        }
        else
        {
            head = list2;
            t1 = list1;
            t2 = list2->next;
        }
        ListNode *ans = head;
        while (t1 != NULL && t2 != NULL)
        {
            if (t1->val < t2->val)
            {
                head->next = t1;
                head = t1;
                t1 = t1->next;
            }
            else
            {
                head->next = t2;
                head = t2;
                t2 = t2->next;
            }
        }
        while (t1 != NULL)
        {
            head->next = t1;
            head = t1;
            t1 = t1->next;
        }
        while (t2 != NULL)
        {
            head->next = t2;
            head = t2;
            t2 = t2->next;
        }
        return ans;
    }
};
// @lc code=end
