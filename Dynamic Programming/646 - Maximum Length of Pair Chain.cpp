//tc: O(n * log N)
//sc: O(n * n)

class Solution {
private:
    static bool comp(const vector<int> &a, const vector<int> &b){
        if( a[1] == b[0] ) return a[1] < b[1];
        return a[1] < b[0];
    }

    static bool compOne(const vector<int> &a, const vector<int> &b){
        return a[0] < b[0];
    }

    int binarySearch(int low, vector<vector<int>> &pr, int k){
        int high = pr.size() - 1;
        int rIdx = pr.size();
        while( low <= high ){
            int mid = low + (high - low) / 2;
            if( pr[mid][0] > k )
                high = mid - 1, rIdx = mid;
            else
                low = mid + 1;
        }
        return rIdx;
    }

    int f(int idx, int j, int n, vector<vector<int>> &pr, vector<vector<int>> &dp){
        if( idx == n ) return 0;
        int &ans = dp[idx][j];
        if( ans != -1 ) return ans;
        int cnt = 0;
        int newIdx = binarySearch(idx, pr, pr[j][1]);
        for(int i = newIdx; i < n; i++){
            cnt = max(cnt, 1 + f(i + 1, i, n, pr, dp));
        }
        return ans = cnt;
    }

public:
    int findLongestChain(vector<vector<int>>& pr) {
        sort(pr.begin(), pr.end(), comp);
        // sort(pr.begin(), pr.end(), compOne);
        // for(auto &a : pr){
        //     cout << a[0] << " " << a[1] << endl;
        // }
        int n = pr.size();
        int maxLen = 0;
        vector<vector<int>> dp(n, vector<int> (n, -1));
        for(int i = 0; i < n; i++){
            maxLen = max(maxLen, 1 + f(i + 1, i, n, pr, dp));
        }
        return maxLen;
    }
};
