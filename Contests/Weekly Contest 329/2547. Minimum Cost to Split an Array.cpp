//problem Link: https://leetcode.com/problems/minimum-cost-to-split-an-array/description/

//time Complexity: O(N ^ 2)
//space Complexity: O(N)

class Solution {
private:
    int countSingals(map<int, int> &freq){
        int count = 0;
        for(auto &a : freq) count += (a.second == 1);
        return count;
    }
    
    int dp[1001];
    
    int func(int idx, int n, vector<int> &nums, int k){
        if( idx == n ) return 0;
        if( dp[idx] != -1 ) return dp[idx];
        int mini = 2e9;
        int freq[n];
        memset(freq, 0, sizeof(freq));
        int count = 0;
        for(int i = idx; i < n; i++){
            freq[nums[i]] += 1;
            if( freq[nums[i]] == 1 )
                ++count;
            if( freq[nums[i]] == 2 )
                --count;
            int currCost = k + ((i - idx + 1) - count) + func(i + 1, n, nums, k);
            mini = min(mini, currCost);
        }
        return dp[idx] = mini;
    }
        
public:
    int minCost(vector<int>& nums, int k) {
        memset(dp, -1, sizeof(dp));
        int mini = func(0, nums.size(), nums, k);
        return mini;
    }
};