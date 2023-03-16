//tc: O(n ^ 2)
//sc: O(1)

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int maxVal = -1e9;
            int minVal = 1e9;
            for(int j = i; j < n; j++){
                maxVal = max(maxVal, nums[j]);
                minVal = min(minVal, nums[j]);
                sum += maxVal - minVal;
            }
        }
        return sum;
    }
};
