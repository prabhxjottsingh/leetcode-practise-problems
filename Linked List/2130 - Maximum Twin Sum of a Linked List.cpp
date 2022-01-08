//Tags: Medium Linked Lists
//PRoblem Link: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
//Time Complexity: O(N) (tranversing thorough the likned list for one time
//Space Complextiy: O(n) -> taken th ehelp of the array

//constant space approach->Take the half linkedlist reverse the other half linked list and then find the maxSum

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
    int pairSum(ListNode *head)
    {
        vector<int> v;
        while (head)
        {
            v.push_back(head->val);
            head = head->next;
        }
        int n = v.size();
        int maxSum = 0;
        for (int i = 0; i < n / 2; i++)
        {
            maxSum = max(maxSum, v[i] + v[n - i - 1]);
        }
        return maxSum;
    }
};