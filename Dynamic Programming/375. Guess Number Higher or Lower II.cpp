//tc: O(n * n * n)
//sc: O(n * n)

class Solution {
private:
    int dp[201][201];

    int func(int l, int r){
        if( r == l ){
            return 0;
        }
        else if( r < l )
            return -1e9;
        int &ans = dp[l][r];
        if( ans != -1 ) return ans;
        int minCost = 1e9;
        for(int i = l; i <= r; i++){
            int cost = i + max(func(l, i - 1), func(i + 1, r));
            minCost = min(minCost, cost);
        }
        return ans = minCost;
    }

public:
    int getMoneyAmount(int n) {
        memset(dp, -1, sizeof(dp));
        int minAmount = func(1, n);
        return minAmount;
    }
};
