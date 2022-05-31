// Problem Link: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/

// Time Complexity: O(N * K),  O(K) -> is the TC of erase function
// Space Compleixty: O(1 << K)

class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        unordered_set<string> st;
        int n = s.size();
        string dq;
        for (int i = 0; i < min(n, k); i++)
        {
            dq.push_back(s[i]);
        }
        st.insert(dq);
        for (int i = k; i < n; i++)
        {
            dq.erase(0, 1);
            dq.push_back(s[i]);
            st.insert(dq);
        }
        int distinctSubstrings = st.size();
        if (distinctSubstrings != (1 << k))
            return false;
        return true;
    }
};