// Problem Link: https://leetcode.com/problems/most-frequent-number-following-key-in-an-array/

// Time Complexity: O(n)
//Space Complexity: O(n)

class Solution
{
public:
    int mostFrequent(vector<int> &nums, int key)
    {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == key)
            {
                if (i < nums.size() - 1)
                {
                    mp[nums[i + 1]]++;
                }
            }
        }
        int maxTarget = INT_MIN, maxFreq = INT_MIN;
        for (auto &a : mp)
        {
            maxFreq = max(maxFreq, a.second);
            if (maxFreq == a.second)
            {
                maxTarget = a.first;
            }
        }
        return maxTarget;
    }
};