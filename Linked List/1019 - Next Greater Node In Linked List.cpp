//tags: Medium, Linked List
//Problem Link: https://leetcode.com/problems/next-greater-node-in-linked-list/
//Time Complxity: O(N)
//Space Complxity: O(N) => becasue of the use of the stacks

class Solution
{

private:
    vector<int> nextGreaterElement(vector<int> v)
    {
        int n = v.size();
        stack<int> st;
        vector<int> ans;
        bool flag = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i] != v[i + 1])
                flag = false;
        }
        if (flag)
        {
            for (int i = 0; i < n; i++)
                ans.push_back(0);
            return ans;
        }
        ans.push_back(0);
        st.push(v[n - 1]);
        for (int i = n - 2; i >= 0; i--)
        {
            if (!st.empty())
            {
                if (st.top() > v[i])
                {
                    ans.push_back(st.top());
                    st.push(v[i]);
                }
                else
                {
                    while (!st.empty() && (st.top() <= v[i]))
                    {
                        st.pop();
                    }
                    if (st.empty())
                    {
                        ans.push_back(0);
                        st.push(v[i]);
                    }
                    else
                    {
                        ans.push_back(st.top());
                        st.push(v[i]);
                    }
                }
            }
            else
            {
                ans.push_back(0);
                st.push(v[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

public:
    vector<int> nextLargerNodes(ListNode *head)
    {

        vector<int> v;

        while (head)
        {
            v.push_back(head->val);
            head = head->next;
        }

        vector<int> ansVector = nextGreaterElement(v);
        return ansVector;
    }
};