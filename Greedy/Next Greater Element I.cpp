//Tag: Easy
//Problem Link: https://leetcode.com/problems/next-greater-element-i/submissions/
//Time Complexity: O(n2^2 + n1)
//Space Complexity: O(n2 + n1)

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<pair<int, int>> ans;
        int n1 = nums1.size();
        int i, j, n2 = nums2.size();
        for (i = 0; i < n2; i++)
        {
            for (j = i + 1; j < n2; j++)
            {
                if (nums2[j] > nums2[i])
                {
                    ans.push_back({nums2[i], nums2[j]});
                    break;
                }
            }
            if (j == n2)
                ans.push_back({nums2[i], -1});
        }
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