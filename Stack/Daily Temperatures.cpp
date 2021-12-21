//Tag: Medium
//Problem Link: https://leetcode.com/problems/daily-temperatures/
//Time Complexity: O(n)
//Space Complexity: O(n)

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> st;
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            while ((!st.empty()) && (temperatures[i] > temperatures[st.top()]))
            {
                int index = st.top();
                st.pop();
                ans[index] = (i - index);
            }
            st.push(i);
        }
        return ans;
    }
};