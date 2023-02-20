//tc: O(n * 30)
//sc: O(n * 30)

//dp with bitmasking

class Solution {
private:
    vector<int> pr = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    static const int mod = 1e9 + 7;
    int dp[1001][1 << 11];

    int getMask(int n){
        int sz = pr.size();
        int mask = 0;
        for(int i = 0; i < sz; i++){
            int count = 0;
            while( n % pr[i] == 0 ){
                n /= pr[i];
                count += 1;
            }
            if( count > 1 ) return -1;
            if( count != 0 )
                mask |= (1 << i);
        }
        return mask;
    }

    int f(int i, int n, vector<int> &nums, int prodMask){
        if( i == n ) return 1;
        int &ans = dp[i][prodMask];
        if( ans != -1 ) return ans;
        int notTake = f(i + 1, n, nums, prodMask);
        int newMask = getMask(nums[i]);
        int take = 0;
        if( newMask != -1 && (newMask & prodMask) == 0 )
            take = f(i + 1, n, nums, prodMask | newMask);
        return ans = (take % mod + notTake % mod) % mod;
    }

public:
    int squareFreeSubsets(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int count = f(0, nums.size(), nums, 0);
        int dp[n][1 << ll];
        for(int i = 0; i < n; i++){
            int mask = getMask()
        }
        return count - 1;
    }
};
