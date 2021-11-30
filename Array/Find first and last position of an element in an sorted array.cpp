//Problem Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
//Tags: Array
//Difficulty: Medium
//Time Complexity: O(n)
//This needs to be done in O(log n) time complxity, which will use the concept of binary search


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int z = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==target){
                if(ans.size()==0)
                    ans.push_back(i);
                z = i;
            }
            if(nums[i]>target)
                break;
        }
        if(ans.size()==0){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        ans.push_back(z);
        return ans;
    }
};