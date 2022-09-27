//Time Complexity: O(N)
//Space Complexity: O(N)

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