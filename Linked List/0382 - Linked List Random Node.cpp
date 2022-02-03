//Tags: Medium, Linked List
///Problem link: https://leetcode.com/problems/linked-list-random-node/
//Time Complxity: O(N) => tranversing thriugh the linked list
//use of the rand() function used to pick any element and we have used modulo operator to keep the random integer with in the range of the vecotr size  


class Solution
{

private:
    vector<int> v;

public:
    Solution(ListNode *head)
    {
        while (head)
        {
            v.push_back(head->val);
            head = head->next;
        }
    }

    int getRandom()
    {
        return (v[rand() % v.size()]);
    }
};