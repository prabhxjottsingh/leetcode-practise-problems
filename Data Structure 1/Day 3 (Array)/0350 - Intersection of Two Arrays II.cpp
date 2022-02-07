// Problem Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/

// Time Compleixty: O(n+m)
// Space Complexity: O(n+m)
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mp1, mp2;
        int n = nums1.size(), m = nums2.size();
        for (int i = 0; i < n; i++)
            mp1[nums1[i]]++;
        for (int i = 0; i < m; i++)
        {
            mp2[nums2[i]]++;
        }
        vector<int> ans;
        for (auto a : mp1)
        {
            int x = min(mp1[a.first], mp2[a.first]);
            while (x--)
                ans.push_back(a.first);
        }
        return ans;
    }
};

// Time Complexity: O(n*logn + m*log m + min(n,m))
// Space Compleixty: O(n+m)
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0;
        vector<int> ans;
        while (i < n && j < m)
        {
            if (nums1[i] == nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] > nums2[j])
                j++;
            else
                i++;
        }
        return ans;
    }
};