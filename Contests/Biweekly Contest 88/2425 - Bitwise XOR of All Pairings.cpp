// Problem Link: https://leetcode.com/problems/bitwise-xor-of-all-pairings/

// time Complexity: O(n * log N)
// Space Compelxity: O(n * M)

class Solution
{
public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2)
    {
        map<long long, long long> freq;
        for (auto &a : nums1)
            freq[a] += (long long)nums2.size();
        for (auto &a : nums2)
            freq[a] += (long long)nums1.size();
        int _xor = 0;
        for (auto &a : freq)
        {
            if ((a.second & 1))
                _xor ^= a.first;
        }
        return _xor;
    }
};