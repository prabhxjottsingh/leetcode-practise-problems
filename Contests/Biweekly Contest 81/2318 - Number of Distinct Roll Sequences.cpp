class Solution
{
private:
    static const int mod = 1e9 + 7;
    int dp[7][7][10003];
    int func(int currElem, int prevElem, int n, int count)
    {

        if (count == 2)
        {
            int waysTwo = 0;
            for (int i = 1; i <= 6; ++i)
            {
                if ((i != prevElem) && (__gcd(currElem, i) == 1) && (i != currElem))
                {
                    waysTwo++;
                }
            }
            dp[currElem][prevElem][count] = ((waysTwo) % mod);
        }

        if (dp[currElem][prevElem][count] != -1)
            return dp[currElem][prevElem][count];

        int ways = 0;
        for (int i = 1; i <= 6; ++i)
        {
            if ((i != prevElem) && (__gcd(currElem, i) == 1) && (i != currElem))
            {
                ways = (ways + func(i, currElem, n, count - 1)) % mod;
            }
        }
        return dp[currElem][prevElem][count] = (ways % mod);
    }

public:
    int distinctSequences(int n)
    {
        if (n == 1)
            return 6;
        memset(dp, -1, sizeof(dp));
        int count = 0;
        for (int i = 1; i <= 6; ++i)
            count = (count + func(i, 0, n, n)) % mod;
        return count;
    }
};