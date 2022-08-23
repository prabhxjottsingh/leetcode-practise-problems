// Problem Link: https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

// Time Complexity: (N * log N)
// Space Complexity: O(1)

class Solution
{
private:
    int binarySearch(long long success, vector<int> &potions, int x)
    {
        int low = 0;
        int high = potions.size() - 1;
        int count = potions.size();
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (potions[mid] * 1ll * x >= success)
            {
                count = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return potions.size() - count;
    }

public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        sort(potions.begin(), potions.end());
        vector<int> res;
        for (auto &a : spells)
        {
            int countSuccessFullPairs = binarySearch(success, potions, a);
            res.push_back(countSuccessFullPairs);
        }
        return res;
    }
};