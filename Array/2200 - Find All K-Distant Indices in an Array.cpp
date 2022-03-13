// Problem Link: https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/

class Solution
{
public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
    {
        vector<int> ans;
        set<int> st;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (abs(i - j) <= k && nums[j] == key)
                    st.insert(i);
            }
        }
        for (auto &a : st)
            ans.push_back(a);
        return ans;
    }
};