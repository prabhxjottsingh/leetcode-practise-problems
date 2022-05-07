// Problem Link: https://leetcode.com/problems/132-pattern/

// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        stack<pair<int, int>> st;
        int currMin = nums[0];
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {

            while (!st.empty() && st.top().first <= nums[i])
            {
                st.pop();
            }

            if (!st.empty() && st.top().second < nums[i])
                return true;

            st.push({nums[i], currMin});
            currMin = min(nums[i], currMin);
        }
        return false;
    }
};