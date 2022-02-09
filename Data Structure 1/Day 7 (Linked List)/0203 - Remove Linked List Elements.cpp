// Problem Link: https://leetcode.com/problems/remove-linked-list-elements/

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *temp = head, *prev = head;
        while (temp)
        {
            while (temp && temp->val == val)
            {
                prev->next = temp->next;
                temp = temp->next;
            }
            prev = temp;
            if (temp)
                temp = temp->next;
        }
        if (head && head->val == val)
            head = head->next;
        return head;
    }
};