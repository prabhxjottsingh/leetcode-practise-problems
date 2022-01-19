//Tags: Medium, Linked List
//Problem Link: https://leetcode.com/problems/swap-nodes-in-pairs/
//Time Complexity: O()
//Space Complexity:

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *temp;
        temp = head->next;
        head->next = swapPairs(head->next->next);
        temp->next = head;
        return temp;
    }
};