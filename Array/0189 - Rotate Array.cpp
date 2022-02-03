//Problem Link: https://leetcode.com/problems/rotate-array/
//Time Complexity: O(n)
//Space Complexity: O(n)

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<pair<int, int>> p;
        for (int i = 0; i < n; i++)
        {
            int x = i + k;
            while (x >= n)
            {
                x = x - n;
            }
            p.push_back({nums[i], x});
        }
        for (auto a : p)
        {
            nums[a.second] = a.first;
        }
    }
};