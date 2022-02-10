// Problem Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return head;
        ListNode *temp = head, *prev = head;
        temp = temp->next;
        while (temp)
        {
            int x = temp->val;
            int y = prev->val;
            if (x != y)
            {
                prev = temp;
                temp = temp->next;
            }
            else
            {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
        }
        return head;
    }
};

// Faster Solution, using Single variable

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *temp = head;
        while (temp)
        {
            while ((temp->next) && (temp->val == temp->next->val))
            {
                auto deleteNode = temp->next;
                temp->next = temp->next->next;
                delete deleteNode; // always free the memory to avoid memory leakage
            }
            temp = temp->next;
        }
        return head;
    }
};