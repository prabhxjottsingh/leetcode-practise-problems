// Problem Link: https://leetcode.com/problems/merge-two-sorted-lists/

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *head = NULL;
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        if (l1->val < l2->val)
        {
            head = l1;
            l1 = l1->next;
        }
        else
        {
            head = l2;
            l2 = l2->next;
        }
        ListNode *finalAns = head;
        while ((l1) && (l2))
        {
            int x = l1->val;
            int y = l2->val;
            if (x < y)
            {
                finalAns->next = l1;
                l1 = l1->next;
            }
            else
            {
                finalAns->next = l2;
                l2 = l2->next;
            }
            finalAns = finalAns->next;
        }
        if (l1)
        {
            finalAns->next = l1;
        }
        else
        {
            finalAns->next = l2;
        }
        return head;
    }
};