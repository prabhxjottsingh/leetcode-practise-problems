// Problem Link: https://leetcode.com/problems/concatenated-words/description/

// Time Complexity: O(N * (L ^ 2))
// space Complexity: O(N * L)

class Solution
{
private:
    bool func(string &a, set<string> &st)
    {
        int n = a.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            if (!dp[i])
                continue;
            for (int j = i + 1; j <= n; j++)
            {
                if (j - i < n && st.count(a.substr(i, j - i)))
                    dp[j] = 1;
            }
            if (dp[n])
                return 1;
        }
        return 0;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](const string &a, const string &b)
             { return a.size() < b.size(); });
        vector<string> v;
        set<string> st;
        for (auto &a : words)
        {
            string str = "";
            bool isPresent = func(a, st);
            if (isPresent)
                v.push_back(a);
            st.insert(a);
        }
        return v;
    }
};