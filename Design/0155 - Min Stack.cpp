// Problem Link: https://leetcode.com/problems/min-stack/description/

// Time Complexity: O(1)
// Space Complexity: O(N)

class MinStack
{
private:
    vector<pair<int, int>> vec;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (vec.empty())
            vec.emplace_back(val, val);
        else
            vec.emplace_back(val, min(val, vec.back().second));
    }

    void pop()
    {
        vec.pop_back();
    }

    int top()
    {
        return vec.back().first;
    }

    int getMin()
    {
        return vec.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */