//{ Driver Code Starts
#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    static const int mod = 1e9 + 7;
    long long int dp[5001];
    long long int func(int n, int k)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return k;
        if (n == 2)
            return k * k;
        if (dp[n] != -1)
            return dp[n];
        long long int caseOne = func(n - 1, k);
        long long int caseTwo = func(n - 2, k);
        long long int final = ((caseTwo + caseOne) * (k - 1)) % mod;
        return dp[n] = final;
    }

public:
    // long long countWays(int n, int k)
    // {
    //     memset(dp, -1, sizeof(dp));
    //     long long count = func(n, k);
    //     return count;
    // }

    // long long countWays(int n, int k){
    //     long long dp[n + 1];
    //     dp[0] = 0;
    //     dp[1] = k;
    //     dp[2] = k * k;
    //     for(int i = 3; i <= n; i++)
    //         dp[i] = ((dp[i - 1] + dp[i - 2]) * (k - 1)) % mod;
    //     return dp[n];
    // }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        cout << ob.countWays(n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends