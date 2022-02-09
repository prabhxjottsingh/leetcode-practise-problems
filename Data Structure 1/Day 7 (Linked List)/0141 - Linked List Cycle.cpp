// Problem Link: https://leetcode.com/problems/linked-list-cycle/

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *rabbit = head;
        ListNode *turtle = head;
        while ((rabbit) && (rabbit->next))
        {
            rabbit = rabbit->next->next;
            turtle = turtle->next;
            if (rabbit == turtle)
                return 1;
        }
        return 0;
    }
};