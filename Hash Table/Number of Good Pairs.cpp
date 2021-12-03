//Tags: Easy
//Problem Link: https://leetcode.com/problems/number-of-good-pairs/
//Time Complexity: O(n)
//Space Complexity: O(n)

//Solved this one using hash table 

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int hsh[101] = {0};
        int ans = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            ans = ans + hsh[nums[i]];
            hsh[nums[i]]++;
        }
        return ans;
    }
};