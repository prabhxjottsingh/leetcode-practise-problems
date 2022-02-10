// Problem Link: https://leetcode.com/problems/reverse-linked-list/

// Reversing Links
class Solution
{
public:
    ListNode *reverseList(ListNode *&head)
    {
        ListNode *q = NULL, *r = NULL, *&p = head;
        while (p)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        // head = q;
        return q;
    }
};

// Using Recursion
class Solution
{
private:
    void reverseLL(ListNode *first, ListNode *second, ListNode *&head)
    {
        if (first)
        {
            reverseLL(first->next, first, head);
            first->next = second;
        }
        else
        {
            head = second;
        }
    }

public:
    ListNode *reverseList(ListNode *&head)
    {
        ListNode *temp = head;
        reverseLL(temp, NULL, head);
        return head;
    }
};

// Using Array

class Solution
{
private:
    void reverseLL(ListNode *&head)
    {
        ListNode *temp = head;
        vector<int> arr;
        while (temp)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        int i = arr.size() - 1;
        while (i > -1)
        {
            temp->val = arr[i];
            i--;
            temp = temp->next;
        }
    }

public:
    ListNode *reverseList(ListNode *&head)
    {
        ListNode *temp = head;
        reverseLL(temp);
        return head;
    }
};