//Problem Link: https://leetcode.com/problems/reorder-list/
//Time Complexity: O(n)
//Space Complexity: O(n) // because of the use of vector

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        vector<int> v;
        ListNode *temp = head;
        while (temp)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }
        int n = v.size();
        temp = head;
        for (int i = 0; i <= n / 2; i++)
        {
            temp->val = v[i];
            if (temp->next)
            {
                temp = temp->next;
                temp->val = v[n - i - 1];
                if (temp->next)
                    temp = temp->next;
            }
        }
        if (temp->next)
            temp->val = v[n / 2];
    }
};