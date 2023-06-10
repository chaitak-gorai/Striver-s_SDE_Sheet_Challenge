/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    bool isPalindrome(ListNode *head)
    {
        stack<int> s;
        ListNode *temp = head;
        while (temp != NULL)
        {

            s.push(temp->val);
            temp = temp->next;
        }
        int flag = 1;
        temp = head;
        while (temp != NULL)
        {
            if (temp->val != s.top())
            {
                flag = 0;
                return false;
            }
            else
            {
                s.pop();
                temp = temp->next;
            }
        }
        if (flag == 1)
        {
            return true;
        }
        return false;
    }
};
// @lc code=end
