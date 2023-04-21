//time Complexity: O(100 * 100 * 100)
//space Complexity: O(100 * 100 * 100)

int dp[101][101][101];
class Solution {
private:
    const int mod = 1e9 + 7;
    int f(int i, int n, int minProfit, vector<int> &group, vector<int> &profit, int k){
        if( i == n || k <= 0 ) return minProfit <= 0;
        int &ans = dp[i][minProfit][k];
        if( ans != -1 ) return ans;
        int cntWays = f(i + 1, n, minProfit, group, profit, k);
        cntWays %= mod;
        if( group[i] <= k )
            cntWays += f(i + 1, n, max(0, minProfit - profit[i]), group, profit, k - group[i]);
        cntWays %= mod;
        ans = cntWays;
        return cntWays;
    }

public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp, -1, sizeof(dp));
        int size = profit.size();
        int cntWays = f(0, size, minProfit, group, profit, n);
        return cntWays;
    }
};
