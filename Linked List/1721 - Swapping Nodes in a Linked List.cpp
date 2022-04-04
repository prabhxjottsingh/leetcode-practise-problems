// Tags: Medium, Linked List
// Problem Link: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
// Time Complexity: O(N)
// Space Complexity: Constant

class Solution
{
private:
    int countNodes(ListNode *head)
    {
        int count = 0;
        ListNode *temp = head;
        while (temp)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }

    int findNodeK(ListNode *head, int k)
    {
        ListNode *temp = head;
        int res = 0, x = 0;
        while (temp)
        {
            x++;
            if (x == k)
            {
                res = temp->val;
                break;
            }
            temp = temp->next;
        }
        return res;
    }

    void changeVal(ListNode *&head, int pos, int newVal)
    {
        ListNode *temp = head;
        int currPos = 0;
        while (temp)
        {
            currPos++;
            if (currPos == pos)
                temp->val = newVal;
            temp = temp->next;
        }
    }

public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        int count = countNodes(head);
        int kFromEnd = count - k + 1;
        int kFromBegin = k;
        int kNodeValFromBegin = findNodeK(head, kFromBegin);
        int KNodeValFromEnd = findNodeK(head, kFromEnd);
        changeVal(head, kFromBegin, KNodeValFromEnd);
        changeVal(head, kFromEnd, kNodeValFromBegin);
        return head;
    }
};