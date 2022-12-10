// Problem Link: https://leetcode.com/problems/reverse-nodes-in-k-group/description/

// Time Complexity: O(N)
// Space Complexity: O(N)

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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head)
            return NULL;
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *currNext = NULL;
        int count = 0;
        while (curr && count < k)
        {
            currNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = currNext;
            count += 1;
        }
        if (curr == NULL && count != k)
        {
            curr = prev;
            prev = NULL;
            currNext = NULL;
            while (count)
            {
                currNext = curr->next;
                curr->next = prev;
                prev = curr;
                curr = currNext;
                count -= 1;
            }
            return prev;
        }
        if (currNext)
            head->next = reverseKGroup(currNext, k);
        return prev;
    }
};