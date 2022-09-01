class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (!headA || !headB)
            return NULL;
        ListNode *tempA = headA;
        ListNode *tempB = headB;
        while (tempA || tempB)
        {
            if (!tempA)
                tempA = headB;
            if (!tempB)
                tempB = headA;
            if (tempA == tempB)
                return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return NULL;
    }
};