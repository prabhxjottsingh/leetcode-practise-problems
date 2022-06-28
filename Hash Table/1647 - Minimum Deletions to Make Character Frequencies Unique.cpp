class Solution
{
public:
    int minDeletions(string s)
    {
        map<char, int> freq;
        int N = 0;
        for (auto &a : s)
        {
            freq[a]++;
            N = max(N, freq[a]);
        }
        vector<bool> isPresent(N + 1, 0);
        int countDelete = 0;
        for (auto &a : freq)
        {
            while (a.second > 0 && isPresent[a.second])
            {
                countDelete++;
                a.second--;
            }
            isPresent[a.second] = 1;
        }
        return countDelete;
    }
};