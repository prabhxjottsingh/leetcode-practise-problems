// Problem Link:https://leetcode.com/problems/3sum-closest/

// time Complexity: O(n * N)
// Space Complexity: O(!)

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int closetSum = INT_MAX;
        int earlierDist = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++)
        {
            int currSum = nums[i];
            int low = i + 1;
            int high = n - 1;
            while (low < high)
            {
                int otherTwo = nums[low] + nums[high];
                currSum += otherTwo;
                int newDist = abs(currSum - target);
                if (newDist < earlierDist)
                {
                    earlierDist = newDist;
                    closetSum = currSum;
                }
                if (currSum < target)
                    low += 1;
                else if (currSum > target)
                    high -= 1;
                else
                    return target;
                currSum -= otherTwo;
            }
        }
        return closetSum;
    }
};