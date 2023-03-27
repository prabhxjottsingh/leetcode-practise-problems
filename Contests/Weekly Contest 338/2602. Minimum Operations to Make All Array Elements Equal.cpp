//time Complexity: O(q * log N)
//space complexity: O(N)

class Solution {
private:
    int binarySearchSmall(vector<int> &nums, int x){
        int low = 0;
        int high = nums.size() - 1;
        int rIdx = -1;
        while( low <= high ){
            int mid = (low + high) / 2;
            if( nums[mid] >= x )
                high = mid - 1;
            else
                low = mid + 1, rIdx = mid;
        }
        return rIdx;
    }

    int binarySearchGreater(vector<int> &nums, int x){
        int low = 0;
        int high = nums.size() - 1;
        int rIdx = nums.size();
        while( low <= high ){
            int mid = (low + high) / 2;
            if( nums[mid] <= x )
                low = mid + 1;
            else
                high = mid - 1, rIdx = mid;
        }
        return rIdx;
    }

public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<long long> rVec;
        sort(nums.begin(), nums.end());
        vector<long long> preSum;
        for(auto &a : nums){
            if( preSum.empty() )
                preSum.push_back(a);
            else
                preSum.push_back(preSum.back() + a);
        }
        for(auto &a : queries){
            int justSmallValIdx = binarySearchSmall(nums, a);
            int justGreaterValIdx = binarySearchGreater(nums, a);
            long long sum = 0;
            if( justSmallValIdx != -1 ){
                long long shldBe = (justSmallValIdx + 1) * 1ll * a;
                long long currSum = preSum[justSmallValIdx];
                sum += shldBe - currSum;
            }
            if( justGreaterValIdx != n ){
                long long shldBe = (n - justGreaterValIdx) * 1ll * a;
                long long currSum = preSum[n - 1];
                if( justGreaterValIdx != 0 )
                    currSum -= preSum[justGreaterValIdx - 1];
                sum += currSum - shldBe;
            }
            rVec.push_back(sum);
        }
        return rVec;
    }
};
