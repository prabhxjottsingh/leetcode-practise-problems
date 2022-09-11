// Problem Link: https://leetcode.com/contest/weekly-contest-310/problems/optimal-partition-of-string/

// time Complexity: O(N * log N)
// space Complexity: O(N)

class Solution
{
public:
    int partitionString(string s)
    {
        set<char> st;
        int count = 1;
        for (auto &a : s)
        {
            if (st.count(a))
            {
                count += 1;
                st.clear();
            }
            st.insert(a);
        }
        return count;
    }
};