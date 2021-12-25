//Tags: Linked List, Medium
//Problem Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
//Time Complexity: O(n)
//Approach, find the middle node using tortoise and rabbit approach and then skip the middle one by pointing directly to the next node from the middle node

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
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head->next == NULL)                                 //edge case: if head have only single element
            return NULL;
        ListNode *slow = head, *fast = head->next->next;
        while ((fast) && (fast->next))
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};