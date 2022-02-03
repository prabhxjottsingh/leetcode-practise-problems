//Tags: Medium
//Problem Link: https://leetcode.com/problems/insert-delete-getrandom-o1/
//Time Complexity: Erasing is constant time function, find function is O(log n) time function

class RandomizedSet
{
private:
    vector<int> st;

public:
    RandomizedSet()
    {
        set<int> st;
    }

    bool insert(int val)
    {
        if (find(st.begin(), st.end(), val) != st.end())
            return false;
        st.push_back(val);
        return true;
    }

    bool remove(int val)
    {
        if (find(st.begin(), st.end(), val) != st.end())
        {
            st.erase(std::remove(st.begin(), st.end(), val), st.end());
            return true;
        }
        return false;
    }

    int getRandom()
    {
        int x = st.size();
        int val = st[rand() % x];
        return val;
    }
};