class Solution
{
private:
    // int dp[2002];
    bool isPal(int start, int end, string &s)
    {
        while (start < end)
        {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    //     int func(int i, int n, string s){
    //         if(i == n)
    //             return dp[i] = 0;
    //         if(dp[i] != -1)
    //             return dp[i];
    //         int minCost = 1e9;
    //         for(int j = i; j < n; j++){
    //             if(isPal(i, j, s)){
    //                 int cost = 1 + func(j + 1, n, s);
    //                 minCost = min(cost, minCost);
    //             }
    //         }
    //         return dp[i] = minCost;
    //     }

public:
    int minCut(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i > -1; i--)
        {
            int minCost = 1e9;
            for (int j = i; j < n; j++)
            {
                if (isPal(i, j, s))
                {
                    int cost = 1 + dp[j + 1];
                    minCost = min(minCost, cost);
                }
            }
            dp[i] = minCost;
        }
        return dp[0] - 1;
    }
};