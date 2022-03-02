// Problem Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> ans;
        int left = 0, right = numbers.size() - 1;
        while (left < right)
        {
            if (numbers[left] + numbers[right] > target)
            {
                right--;
            }
            else if (numbers[left] + numbers[right] < target)
                left++;
            else
            {
                ans.push_back(left + 1);
                ans.push_back(right + 1);
                return ans;
            }
        }
        return ans;
    }
};