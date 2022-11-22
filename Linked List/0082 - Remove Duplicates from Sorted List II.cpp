// Problem Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

// Time Complexity: O(N)
// Space Complexity: O(1)

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        while (curr)
        {
            int currVal = curr->val;
            if (curr->next && curr->next->val == currVal)
            {
                while (curr->next && curr->next->val == currVal)
                    curr = curr->next;
                if (!curr->next)
                {
                    if (!prev)
                        return NULL;
                    prev->next = NULL;
                    break;
                }
                else
                {
                    if (!prev)
                        head = curr->next;
                    else
                        prev->next = curr->next;
                    curr = curr->next;
                }
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};