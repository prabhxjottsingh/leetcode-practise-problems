// Problem Link: https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/

// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {
        map<int, vector<int>> mp;
        int n = cards.size();
        for (int i = 0; i < n; i++)
        {
            mp[cards[i]].push_back(i);
        }
        int minDiff = 1e9;
        bool foundPair = false;
        for (auto &a : mp)
        {
            if (a.second.size() > 1)
            {
                foundPair = true;
                vector<int> v = a.second;
                int n = v.size();
                for (int i = 0; i < n - 1; i++)
                {
                    minDiff = min(minDiff, v[i + 1] - v[i] + 1);
                }
            }
        }
        if (foundPair == false)
            return -1;
        return minDiff;
    }
};