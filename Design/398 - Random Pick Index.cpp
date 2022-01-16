//Tags: Medium
//Problem Link: https://leetcode.com/problems/random-pick-index/
//Time Complexity: O(n)
//Space Complexity: O(N)

class Solution
{
private:
    vector<int> array;

public:
    Solution(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            array.push_back(nums[i]);
    }

    int pick(int target)
    {
        vector<int> possibleIndex;
        for (int i = 0; i < array.size(); i++)
        {
            if (array[i] == target)
                possibleIndex.push_back(i);
        }
        int x = possibleIndex.size();
        return possibleIndex[rand() % x];
    }
};