// Problem Link: https://leetcode.com/contest/weekly-contest-310/problems/most-frequent-even-element/

// time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
public:
    int mostFrequentEven(vector<int> &nums)
    {
        int num = -1;
        int maxFreq = 0;
        map<int, int> freq;
        for (auto &a : nums)
        {
            if (!(a & 1))
            {
                freq[a] += 1;
                if (maxFreq < freq[a])
                    num = a;
                if (maxFreq == freq[a])
                    num = min(num, a);
                maxFreq = max(maxFreq, freq[a]);
            }
        }
        return num;
    }
};