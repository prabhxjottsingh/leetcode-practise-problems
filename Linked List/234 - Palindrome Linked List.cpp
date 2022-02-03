//Problem Link: https://leetcode.com/problems/palindrome-linked-list/
//Time Complexity: o(n)
//Space Complexity: O(n) -> because of use of vectors

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *front = head, *back = head;
        vector<int> v;
        while (back)
        {
            v.push_back(back->val);
            back = back->next;
        }
        reverse(v.begin(), v.end());
        int i = 0;
        while (front)
        {
            if (front->val != v[i])
                return false;
            front = front->next;
            i++;
        }
        return true;
    }
};