// Time Complexity: O(N)
// Space Complexity: O(60)

// Ptoblem Link: https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/submissions/

class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        int n = time.size();
        map<int, int> mp;
        long long int count = 0;
        int countDivBySixty = 0;
        for (int i = 0; i < n; i++)
        {
            if (time[i] % 60 == 0)
                countDivBySixty++;
            else
                mp[time[i] % 60]++;
        }
        count += 1ll * countDivBySixty * (countDivBySixty - 1) / 2;
        cout << count << endl;
        for (auto &a : mp)
        {
            if (a.first == 60 - a.first)
                count += a.second * (a.second - 1) / 2;
            else if (mp.count(60 - a.first) == 1)
            {
                count += mp[60 - a.first] * a.second;
                mp[a.first] = 0;
            }
        }
        return count;
    }
};