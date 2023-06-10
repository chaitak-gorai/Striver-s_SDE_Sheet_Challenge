/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode *reverseParts(ListNode *head, int k)
    {
        if (head == NULL)
        {
            return NULL;
        }
        if (head->next == NULL)
        {
            return head;
        }
        ListNode *temp = head;
        ListNode *buff = NULL;
        ListNode *head2 = head;
        ListNode *prev = NULL;
        for (int i = 0; i < k - 1; i++)
        {
            if (temp == NULL)
            {
                break;
                return head2;
            }
            temp = temp->next;
        }
        if (temp == NULL)
        {
            return head2;
        }
        if (temp->next != NULL)
        {
            prev = temp->next;
        }
        else
        {
            prev = NULL;
        }

        temp = head;

        for (int i = 0; i < k; i++)
        {
            buff = temp->next;
            temp->next = prev;
            prev = temp;
            temp = buff;
        }
        return prev;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *cur = head;
        int count = 0;
        while (cur)
        {
            count++;
            cur = cur->next;
        }
        ListNode *part = reverseParts(head, k);
        ListNode *res = part;
        for (int i = 0; i < count / k - 1; i++)
        {
            ListNode *temp = part;
            for (int j = 0; j < k - 1; j++)
            {

                temp = temp->next;
            }
            if (temp == NULL)
                return res;
            part = temp;
            cout << part->val;
            part->next = reverseParts(part->next, k);
            part = part->next;
        }
        return res;
    }
};
// @lc code=end
