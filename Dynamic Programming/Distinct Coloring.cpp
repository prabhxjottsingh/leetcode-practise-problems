//problem Link: https://practice.geeksforgeeks.org/problems/844b4fdcd988ac5461324d62d43f7892749a113c/1

//time Complexity: O(N)
//space Complexity: O(n)

class Solution{
public:
    long long int distinctColoring(int n, int r[], int g[], int b[]){
        long long int dp[n][3];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = r[0];
        dp[0][1] = g[0];
        dp[0][2] = b[0];
        for(int i = 1; i < n; i++){
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + r[i];
            dp[i][1] = min(dp[i - 1][2], dp[i - 1][0]) + g[i];
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + b[i];
        }
        return min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    }
};
