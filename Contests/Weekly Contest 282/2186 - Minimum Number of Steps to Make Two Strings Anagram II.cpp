// Problem Link: 2186. Minimum Number of Steps to Make Two Strings Anagram II

// Time Complexity: O(N+M)
// Space Complexity: O(N+M)

class Solution
{
public:
    int minSteps(string s, string t)
    {
        map<char, int> mapOne, mapTwo;
        int n = s.size(), m = t.size();
        for (int i = 0; i < n; i++)
        {
            mapOne[s[i]]++;
        }
        for (int i = 0; i < m; i++)
        {
            mapTwo[t[i]]++;
        }
        int count = 0;
        for (auto &a : mapOne)
        {
            if (mapTwo.count(a.first) == 0)
                count += a.second;
            else if (mapTwo.count(a.first) == 1)
            {
                count += abs(mapTwo[a.first] - mapOne[a.first]);
            }
        }
        for (auto &a : mapTwo)
        {
            if (mapOne.count(a.first) == 0)
            {
                count += a.second;
            }
        }
        return count;
    }
};