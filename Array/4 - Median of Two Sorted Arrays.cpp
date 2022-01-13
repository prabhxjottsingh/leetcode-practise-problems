//Tags: Hard, Array
//Problem Link: https://leetcode.com/problems/median-of-two-sorted-arrays/
//Time Complexity: O((n*log n) + n+m)
//Space Complexity: O(n+m)

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> merged;
        int n = nums1.size(), m = nums2.size();
        for (int i = 0; i < n; i++)
            merged.push_back(nums1[i]);
        for (int i = 0; i < m; i++)
            merged.push_back(nums2[i]);
        sort(merged.begin(), merged.end());
        if ((n + m) % 2 != 0)
        {
            double ans = merged[(n + m) / 2];
            return ans;
        }
        else
        {
            double ans = ((double)merged[(n + m) / 2] + (double)merged[(n + m) / 2 - 1]) / 2;
            return ans;
        }
    }
};