// Problem Link: https://leetcode.com/problems/find-the-difference-of-two-arrays/

// Time Complexity of this code can be decreased by using maps, but that would eventually increase the space complexity

class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> finalAns(2);
        for (int i = 0; i < nums1.size(); i++)
        {
            if (find(nums2.begin(), nums2.end(), nums1[i]) == nums2.end() && (find(finalAns[0].begin(), finalAns[0].end(), nums1[i]) == finalAns[0].end()))
            {
                finalAns[0].push_back(nums1[i]);
            }
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            if (find(nums1.begin(), nums1.end(), nums2[i]) == nums1.end() && (find(finalAns[1].begin(), finalAns[1].end(), nums2[i]) == finalAns[1].end()))
            {
                finalAns[1].push_back(nums2[i]);
            }
        }
        return finalAns;
    }
};