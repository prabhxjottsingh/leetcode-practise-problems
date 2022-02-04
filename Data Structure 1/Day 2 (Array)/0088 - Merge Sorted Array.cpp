// Problem Link: https://leetcode.com/problems/merge-sorted-array/

// Time Complexity: O(n + m + (n+m)*log(n+m))
// Space Complexity: O(n+m)

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> ans;
        for (int i = 0; i < m; i++)
            ans.push_back(nums1[i]);
        for (int i = 0; i < n; i++)
            ans.push_back(nums2[i]);
        sort(ans.begin(), ans.end());
        for (int i = 0; i < m; i++)
            nums1[i] = ans[i];
        for (int i = m; i < m + n; i++)
            nums1[i] = (ans[i]);
    }
};


//Time Complexity: O(n) -> Single Pass Solution
