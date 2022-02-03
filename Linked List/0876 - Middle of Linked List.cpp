//Tag: Linked List, Easy
//Problem Link: https://leetcode.com/problems/middle-of-the-linked-list/
//Time Complexity: O(n/2)

//with the help of two pointer approach

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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        while ((fast->next) && (fast->next->next))
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast->next)                               //in-case size of linked list is an even number then we need to return the second node of the two middle nodes
            slow = slow->next;
        return (slow);
    }
};