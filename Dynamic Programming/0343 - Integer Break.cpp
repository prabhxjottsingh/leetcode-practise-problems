class Solution {
private:
    int dp[59];
    int func(int n) {

        if ( n < 2 )
            return 1;

        if ( dp[n] != -1 )
            return dp[n];

        int maxProd = 0;
        for (int i = 2; i <= n; i++)
            maxProd = max(maxProd, i * func( n - i ));

        return dp[n] = maxProd;

    }

public:
    int integerBreak(int n) {
        memset(dp, -1, sizeof(dp));
        int count = func(n);
        if ( n < 4 )
            return n - 1;
        return count;
    }
};