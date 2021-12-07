//Tags: Easy
//Problem Link: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
//Time Complexity: O(n)
//Space Complexity: O(n)



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
    string linkedListToBinaryString(ListNode *head)
    {
        string s;
        while (head != NULL)
        {
            s.push_back(head->val);
            head = head->next;
        }
        return s;
    }

    int getDecimalValue(ListNode *head)
    {
        string s = linkedListToBinaryString(head);
        int n = s.length();
        int x = 0, power = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            x = x + pow(2, power) * s[i];
            power++;
        }
        return x;
    }
};