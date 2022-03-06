// Problem Link: https://leetcode.com/problems/replace-non-coprime-numbers-in-array/

// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
public:
    vector<int> replaceNonCoprimes(vector<int> &nums)
    {
        stack<int> st;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                st.push(nums[i]);
            }
            else
            {
                int x = st.top();
                int y = nums[i];
                int gcdOfAdjacent = __gcd(x, y);
                while (!st.empty() && gcdOfAdjacent > 1)
                {
                    st.pop();
                    int LCM = lcm(x, y);
                    y = LCM;
                    if (!st.empty())
                        x = st.top();
                    gcdOfAdjacent = __gcd(x, y);
                }
                st.push(y);
            }
        }
        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};