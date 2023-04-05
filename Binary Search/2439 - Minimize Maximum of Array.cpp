//time Complexity: O(n * log n)
//space Complexity: O(n)

class Solution {
private:
    bool isPosVal(int k, vector<long long> nums){
        int n = nums.size();
        for(int i = n - 2; i > -1; i--){
            if( nums[i + 1] > k ){
                long long diff = nums[i + 1] - k;
                nums[i] += diff;
            }
        }
        return nums[0] <= k;
    }

public:
    int minimizeArrayValue(vector<int>& nums) {
        vector<long long> arr(nums.begin(), nums.end());
        int low = 0;
        int high = 2e9;
        int minMaxVal = 2e9;
        while( low <= high ){
            int mid = low + (high - low) / 2;
            if( isPosVal(mid, arr) ){
                high = mid - 1;
                minMaxVal = mid;
            }
            else
                low = mid + 1;
        }
        return minMaxVal;
    }
};
