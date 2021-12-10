class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<pair<int, int>> ans;
        int n1 = nums1.size();
        int i, j, n2 = nums2.size();
        stack<int> st;
        for (int i = n2 - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() < nums2[i])
                st.pop();
            if (!st.empty() && st.top() > nums2[i])
            {
                ans.push_back({nums2[i], st.top()});
            }
            if (st.empty())
                ans.push_back({nums2[i], -1});
            st.push(nums2[i]);
        }
        reverse(ans.begin(), ans.end());
        vector<int> finalAns;
        for (i = 0; i < n1; i++)
        {
            for (auto a : ans)
            {
                if (a.first == nums1[i])
                    finalAns.push_back(a.second);
            }
        }
        return finalAns;
    }
};