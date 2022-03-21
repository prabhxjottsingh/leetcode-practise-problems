// Problem Link: https://leetcode.com/problems/count-hills-and-valleys-in-an-array/


//I believe this is the best solution, because a solution with O(1) space must have a very high complexity if all the integers of the array are equal

// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
public:
    int countHillValley(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> newV;
        newV.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            if (newV.back() != nums[i])
                newV.push_back(nums[i]);
        }
        int count = 0;
        for (int i = 1; i < newV.size() - 1; i++)
        {
            if (((newV[i] > newV[i + 1] && newV[i] > newV[i - 1]) || (newV[i] < newV[i + 1] && newV[i] < newV[i - 1])))
            {
                count++;
            }
        }
        return count;
    }
};

