// Problem Link: https://leetcode.com/problems/find-original-array-from-doubled-array/

// Time Complexity: O(N * log N)
// space Complexity: O(N)

class Solution
{
private:
    static const int N = 1e5 + 3;

public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        sort(changed.begin(), changed.end());
        int freq[2 * N];
        vector<int> orig;
        memset(freq, 0, sizeof(freq));
        for (auto &a : changed)
        {
            freq[a] += 1;
        }
        for (auto &a : changed)
        {
            if (freq[a] == 0)
                continue;
            if ((freq[2 * a] == 0) || ((int)changed.size() & 1))
                return {};
            freq[a] -= 1;
            freq[2 * a] -= 1;
            orig.push_back(a);
        }
        return orig;
    }
};