//Tags: Medium, Linked List
//Problem Link: https://leetcode.com/problems/sort-list/
//Time Complxity: O(N + Nlog N) ~ O(N* Log N)
//Space Complexity: O(N)=> because of the vector

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        vector<int> v;
        ListNode *temp = head;
        while (temp)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }
        sort(v.begin(), v.end());
        ListNode *temp2 = head;
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            temp2->val = v[i];
            temp2 = temp2->next;
        }
        return head;
    }
};