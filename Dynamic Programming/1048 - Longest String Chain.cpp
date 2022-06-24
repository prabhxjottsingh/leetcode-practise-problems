class Solution
{
private:
    bool isPossible(string a, string b)
    {
        if ((a.size() - b.size()) != 1)
            return false;
        int first = 0;
        int second = 0;
        while (first < a.size())
        {
            if (second < b.size() && a[first] == b[second])
            {
                first++;
                second++;
            }
            else
                first++;
        }
        if (first == a.size() && second == b.size())
            return true;
        return false;
    }

    static bool comp(string &a, string &b)
    {
        return a.size() < b.size();
    }

public:
    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), comp);
        int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if ((isPossible(words[i], words[prev])) && (1 + dp[prev] > dp[i]))
                    dp[i] = 1 + dp[prev];
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};