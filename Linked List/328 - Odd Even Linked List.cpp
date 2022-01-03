//Tags: Medium, Linked List
//Problem Link: https://leetcode.com/problems/odd-even-linked-list/
//Time Complxity: O(N)
//Approach: We are making two lists, and in one storing even position and in other odd positioned
//then we will connect the first even positioned with the last odd positions and tada

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
            return head;
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *firstEven = head->next;

        while ((odd->next) && (even->next))
        {
            odd->next = even->next;
            even->next = odd->next->next;
            odd = odd->next;
            even = even->next;
        }

        odd->next = firstEven;
        return head;
    }
};