//tc: O(n * log N)
//sc: O(n)

class Solution {
private:
    int binarySearch(int i, int low, int high, vector<long long> &preSum, long long k, vector<int> &nums){
        int resIdx = low - 1;
        while( low <= high ){
            int mid = (low + high) / 2;
            long long currScore = preSum[mid] - preSum[i] + nums[i];
            int len = mid - i + 1;
            currScore *= len;
            if( currScore < k )
                resIdx = mid, low = mid + 1;
            else
                high = mid - 1;
        }
        return resIdx;
    }

public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long count = 0;
        vector<long long> preSum;
        preSum.push_back(nums[0]);
        int n = nums.size();
        for(int i = 1; i < n; i++)
            preSum.push_back(preSum.back() + nums[i]);
        for(int i = 0; i < n; i++){
            int nextIdx = binarySearch(i, i, n - 1, preSum, k, nums);
            count += nextIdx - i + 1;
        }
        return count;
    }
};
