// Problem Link: https://leetcode.com/problems/summary-ranges/

// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ans;
        if (nums.size() == 0)
            return ans;
        int currIndex = 0, singleElement = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            currIndex = i, singleElement = i;
            while ((currIndex + 1 < nums.size()) && (nums[currIndex + 1] == nums[currIndex] + 1))
                currIndex++;
            if (currIndex == singleElement)
                ans.push_back(to_string(nums[currIndex]));
            else
                ans.push_back(to_string(nums[singleElement]) + "->" + to_string(nums[currIndex]));
            i = currIndex;
        }
        return ans;
    }
};