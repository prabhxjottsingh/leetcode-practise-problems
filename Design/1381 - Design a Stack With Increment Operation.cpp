//Problem Link: https://leetcode.com/problems/design-a-stack-with-increment-operation/
//Time Complexity: O(n)
//Space Complexity: O(n) -> use of stack

class CustomStack
{
private:
    int size = 0;
    stack<int> st;

public:
    CustomStack(int maxSize)
    {
        size = maxSize;
    }

    void push(int x)
    {
        if (st.size() < size)
            st.push(x);
        else
            return;
    }

    int pop()
    {
        if (!st.empty())
        {
            int x = st.top();
            st.pop();
            return x;
        }
        else
            return -1;
    }

    void increment(int k, int val)
    {
        stack<int> extra;

        while (!st.empty())
        {
            int topa = st.top();
            st.pop();
            extra.push(topa);
        }

        k = min(k, size);
        while (!extra.empty())
        {
            int topa = extra.top();
            if (k > 0)
            {
                topa = topa + val;
                k--;
            }
            extra.pop();
            st.push(topa);
        }
    }
};