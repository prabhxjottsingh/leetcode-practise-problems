// Problem Link: https://leetcode.com/problems/design-a-stack-with-increment-operation/
// Time Complexity: O(n)
// Space Complexity: O(n) -> use of stack

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

// Time Complexity: O(N)
// Space Complexity: O(N)

class CustomStack
{
private:
    vector<pair<int, int>> vec;
    int size;
    int idx = 0;

public:
    CustomStack(int maxSize)
    {
        size = maxSize;
        vec.resize(maxSize);
        idx = 0;
    }

    void push(int x)
    {
        if (idx < 0)
            idx = 0;
        if (idx < size)
        {
            vec[idx].first = x;
            vec[idx].second = 0;
            idx += 1;
        }
    }

    int pop()
    {
        idx -= 1;
        if (idx < 0)
            return -1;
        if (idx > 0)
            vec[idx - 1].second += vec[idx].second;
        int removedElem = vec[idx].first + vec[idx].second;
        // vec[idx].second = 0;
        // idx -= 1;
        return removedElem;
    }

    void increment(int k, int val)
    {
        k = min({k - 1, idx - 1, size - 1});
        if (k < 0)
            return;
        vec[k].second += val;
    }

    void printVec()
    {
        for (int i = 0; i < idx; i++)
            cout << vec[i].first << " " << vec[i].second << endl;
        cout << endl;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */