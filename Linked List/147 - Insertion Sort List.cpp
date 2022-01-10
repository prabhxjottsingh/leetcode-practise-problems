//Tags: LinkedList, Medium, Sorting
//Problem Link:
//Time Complexity: O(N Log N + N)
//Space Complexity: O(N) (becasue of vector)

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
    ListNode *insertionSortList(ListNode *head)
    {
        vector<int> v;
        ListNode *temp = head;
        while (temp)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }
        sort(v.begin(), v.end());
        temp = head;
        int i = 0;
        while (temp)
        {
            temp->val = v[i];
            i++;
            temp = temp->next;
        }
        return head;
    }
};