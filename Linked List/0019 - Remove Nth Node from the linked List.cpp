//Tags: Linked List, Medium
//Problem Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
//Time Complexity: O(n)
//Approach, firstly we will iterate to the Nth node from starting using one pointer, and then use fast and slow pointer then using slow pointer skip the nth node 

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
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < n; i++)
            fast = fast->next;
        if (fast == NULL)
            return head->next;
        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};