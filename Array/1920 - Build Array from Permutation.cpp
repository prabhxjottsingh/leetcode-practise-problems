// Tags: Array
// Difficulty: Easy
//Problem Link: https://leetcode.com/problems/build-array-from-permutation/
//Time Complexity: O(n)
//Space Complexity: O(n)
//solution (that I thought)
//just followed the instructions as they were given in the question, always read the question carefully

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        int i,n = nums.size();
        for(i=0; i<n; i++)
            ans.push_back(nums[nums[i]]);
        return ans;
    }
};

//Now in the discussion section I came through the another approach and came to know that it can be done in O(1) space complexity too, which is a much better approach
//simply thought to store two values in one position, As the values in the input array are ranging from 0 to n-1 where n is length of array. I can simply store the input array value in modulo by n and modified value in divide by n. 


class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]+(n*(nums[nums[i]]%n));
        }
        for(int i=0;i<n;i++){
            nums[i]/=n;
        }
        return nums;
    }
};