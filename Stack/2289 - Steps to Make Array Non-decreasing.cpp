// Problem Link: https://leetcode.com/problems/steps-to-make-array-non-decreasing/

// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    int totalSteps(vector<int> &nums)
    {
        stack<pair<int, int>> st;
        int n = nums.size();
        int finalSteps = 0;
        for (int i = n - 1; i > -1; i--)
        {
            int countStepsTemp = 0;
            while (st.size() && nums[i] > st.top().first)
            {
                countStepsTemp += 1;
                countStepsTemp = max(countStepsTemp, st.top().second);
                st.pop();
            }
            st.push({nums[i], countStepsTemp});
            finalSteps = max(finalSteps, countStepsTemp);
        }
        return finalSteps;
    }
};