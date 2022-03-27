// Problem Link: https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution
{
public:
    int minDeletion(vector<int> &nums)
    {
        stack<int> st;
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                st.push(nums[i]);
            }
            else
            {
                if (st.top() == nums[i] && (st.size() & 1))
                {
                    count++;
                }
                else
                {
                    st.push(nums[i]);
                }
            }
        }
        if (st.size() & 1)
            count++;
        return count;
    }
};