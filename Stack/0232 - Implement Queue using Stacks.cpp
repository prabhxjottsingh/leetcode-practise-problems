// Problem Link: https://leetcode.com/problems/implement-queue-using-stacks/

// Time Complexity: O(n)
// Space complexity: O(2*n)

class MyQueue
{
private:
    stack<int> first, second;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        first.push(x);
    }

    int pop()
    {
        while (!first.empty())
        {
            second.push(first.top());
            first.pop();
        }
        int x = second.top();
        second.pop();
        while (!second.empty())
        {
            first.push(second.top());
            second.pop();
        }
        return x;
    }

    int peek()
    {
        while (!first.empty())
        {
            second.push(first.top());
            first.pop();
        }
        int x = second.top();
        while (!second.empty())
        {
            first.push(second.top());
            second.pop();
        }
        return x;
    }

    bool empty()
    {
        return first.empty();
    }
};
