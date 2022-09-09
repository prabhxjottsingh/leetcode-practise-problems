// Problem Link: https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/

// time Complexity: O(N * log N)
// Space Complexity: O(1)

class Solution
{
private:
    static bool comp(const vector<int> &a, const vector<int> &b)
    {
        if (a[0] == b[0])
            return b[1] < a[1];
        return (b[0] > a[0]);
    }

public:
    int numberOfWeakCharacters(vector<vector<int>> &properties)
    {
        sort(properties.begin(), properties.end(), comp);
        int n = properties.size();
        int count = 0;
        int maxDefenseTillNow = 0;
        int maxAttackTillNow = 0;
        for (int i = n - 1; i > -1; i--)
        {
            if (properties[i][1] < maxDefenseTillNow && properties[i][0] < maxAttackTillNow)
                count += 1;
            maxDefenseTillNow = max(maxDefenseTillNow, properties[i][1]);
            maxAttackTillNow = max(maxAttackTillNow, properties[i][0]);
        }
        return count;
    }
};