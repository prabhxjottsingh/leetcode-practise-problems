//Difficulty: Easy\
//Space Complexity: O(N)
//Time Complxity: O(N + n)
//Problem Link: https://leetcode.com/problems/missing-number/

//most correct answer
class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int n = nums.size();
        int formulae = (n*(n+1))/2;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum+=nums[i];
        }
        return (formulae-sum);
    }
};

//another approach using hashing

class Solution {
public:
    
    static const int N = 1e4+7;
    int hsh[N];
    
    void makeAllHashZero(){
        for(int i = 0; i<N; i++)
            hsh[i] = 0;
    }
    
    void hashTheVector(vector<int> &v){
        int n = v.size();
        for(int i = 0; i<n; i++)
            hsh[v[i]] = 1;
    }
    
    int missingNumber(vector<int>& nums) {
        makeAllHashZero();   
        hashTheVector(nums);
        for(int i = 0; i < N; i++){
            if(hsh[i]==0)
                return i;
        }
        return -1;
    }
};

//better approach came to mind later on
class Solution {
public:
    int missingNumber(vector<int>& nums) {
       sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]!=i)
                return i;
        }
        return nums.size();
    }
};