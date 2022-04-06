//Problem Link: https://leetcode.com/problems/find-triangular-sum-of-an-array/

//Time Complexity: O(N^N)
//Space Complexity: O(1)

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        for(int i = 1; i < nums.size(); i++)
            nums[i-1] = ((nums[i-1] + nums[i]) % 10);
        nums.resize(nums.size() - 1);
        return triangularSum(nums);
    }
};