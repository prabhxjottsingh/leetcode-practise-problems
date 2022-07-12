class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        int dp[n];
        deque<int> dq;
        dp[n - 1] = nums[n - 1];
        dq.push_front(n - 1);
        for (int i = n - 2; i > -1; i--) {
            if ( dq.front() - i > k )
                dq.pop_front();
            dp[i] = nums[i] + dp[dq.front()];
            while ( dq.size() && dp[dq.back()] < dp[i] )
                dq.pop_back();
            dq.push_back(i);
        }
        return dp[0];
    }
};