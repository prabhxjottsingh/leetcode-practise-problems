//tc: O(n * k * log N)
//sc: O(n * k)

class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        int k = costs[0].size();
        if( k == 1 ){
            if( n == 1 ) return costs[0][0];
            return -1;
        }
        vector<vector<int>> dp(2, vector<int> (k, 1e9));
        int maxVal = 1e9, maxValIdx = -1;
        int secondMaxVal = 1e9;
        for(int i = 0; i < k; i++){
            dp[0][i] = costs[0][i];
            if( dp[0][i] <= maxVal ){
                secondMaxVal = maxVal;
                maxVal = dp[0][i];
                maxValIdx = i;
            }
        }
        for(int i = 1; i < n; i++){
            int tMaxVal = 1e9, tMaxValIdx = -1;
            int tSecondMaxVal = 1e9;
            for(int j = 0; j < k; j++){
                if( maxValIdx != j )
                    dp[1][j] = min(dp[1][j], maxVal + costs[i][j]);
                else
                    dp[1][j] = min(dp[1][j], secondMaxVal + costs[i][j]);
                if( dp[1][j] <= tMaxVal ){
                    tSecondMaxVal = tMaxVal;
                    tMaxVal = dp[1][j];
                    tMaxValIdx = j;
                }
            }
            dp[0] = dp[1];
            for(int j = 0; j < k; j++)
                dp[1][j] = 1e9;
            maxVal = tMaxVal;
            secondMaxVal = tSecondMaxVal;
            maxValIdx = tMaxValIdx;
        }
        int minCost = 1e9;
        for(int i = 0; i < k; i++){
            // if( dp[0][i] == 1e9 ) return -1;
            minCost = min(minCost, dp[0][i]);
        }
        return minCost;
    }
};
