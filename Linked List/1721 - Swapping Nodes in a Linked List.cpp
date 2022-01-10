//Tags: Medium, Linked List
//Problem Link: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
//Time Complexity: O(N)
//Space Complexity: Constant

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
    ListNode *swapNodes(ListNode *head, int k)
    {
        int kFront = 0, KRear = k, kFront2, kRear2;
        int kFrontInteger = 0, kRearInteger = 0, count = 0;
        ListNode *temp1 = head, *temp2 = head, *temp3 = head;
        while (temp1)
        {
            kFront++;
            count++;
            if (kFront == k)
            {
                kFrontInteger = temp1->val;
            }
            temp1 = temp1->next;
        }
        KRear = kRear2 = count - k;
        while (temp2)
        {
            KRear--;
            if (KRear == -1)
            {
                kRearInteger = temp2->val;
            }
            temp2 = temp2->next;
        }
        kRear2++;
        while (temp3)
        {
            k--;
            kRear2--;
            if (k == 0)
                temp3->val = kRearInteger;
            if (kRear2 == 0)
                temp3->val = kFrontInteger;
            temp3 = temp3->next;
        }
        return head;
    }
};