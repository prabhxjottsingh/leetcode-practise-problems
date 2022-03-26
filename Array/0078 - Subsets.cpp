// Problem Link: https://leetcode.com/problems/subsets/

class Solution
{
private:
    void generateSubset(vector<int> &v, int i, vector<int> &temp, map<vector<int>, int> &mp, vector<vector<int>> &subset)
    {
        if (i == v.size())
        {
            if (!mp.count(temp))
                subset.push_back(temp);
            return;
        }
        temp.push_back(v[i]);
        generateSubset(v, i + 1, temp, mp, subset);
        temp.pop_back();
        generateSubset(v, i + 1, temp, mp, subset);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> subset;
        vector<int> temp;
        map<vector<int>, int> mp;
        generateSubset(nums, 0, temp, mp, subset);
        return subset;
    }
};

//Using Bits

//Time Complexity: O( N * (2^N) )
//Space Complexity: O(1)

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int numberOfSubsets = (1 << n);
        vector<vector<int>> subsets;
        for(int mask = 0; mask < numberOfSubsets; mask++){
            vector<int> subset;
            for(int i = 0; i < n; i++){
                if( (mask & (1 << i)) != 0 )
                    subset.push_back(nums[i]);
            }
            subsets.push_back(subset);
        }
        return subsets;
    }
};