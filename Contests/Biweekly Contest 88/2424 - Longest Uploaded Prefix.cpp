// Problem Link: https://leetcode.com/problems/longest-uploaded-prefix/

// time Complexity: O(N *log N)
// Space complexity: O(N)

class LUPrefix
{
private:
    set<int> st;
    int maxSize = 0;

public:
    LUPrefix(int n)
    {
        for (int i = 1; i <= n; i++)
            st.insert(i);
        maxSize = n;
    }

    void upload(int video)
    {
        st.erase(video);
    }

    int longest()
    {
        if (st.empty())
            return maxSize;
        return *st.begin() - 1;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */