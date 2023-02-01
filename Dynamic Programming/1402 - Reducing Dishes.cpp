//problem Link: https://leetcode.com/problems/reducing-dishes/description/

//tc: O(n * m)
//sc: O(n)

//recursive Solutino:

class Solution {
private:
    int dp[2001][502];

    int func(int idx, int n, vector<int> &sat, int time){
        if( idx == n ) return 0;
        if( dp[time][idx] != -1 ) return dp[time][idx];
        return dp[time][idx] = max(sat[idx] * time + func(idx + 1, n, sat, time + 1), func(idx + 1, n, sat, time));
    }

public:
    int maxSatisfaction(vector<int>& sat) {
        memset(dp, -1, sizeof(dp));
        sort(sat.begin(), sat.end());
        int maxVal = func(0, sat.size(), sat, 1);
        return maxVal;
    }
};

//iterative Solution:
class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        int n = sat.size();
        sort(sat.begin(), sat.end());
        int dp[n + 1][n + 1];
        for(int i = 0; i <= n; i++){
            dp[i][0] = 0;
            for(int j = 1; j <= n; j++)
                dp[i][j] = -1e9;
        }
        int maxVal = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                dp[i][j] = max(dp[i - 1][j], (sat[i - 1] * j) + dp[i - 1][j - 1]);
                maxVal = max(maxVal, dp[i][j]);
            }
        }
        return maxVal;
    }
};
