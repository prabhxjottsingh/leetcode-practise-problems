// Problem link: https://leetcode.com/problems/flip-string-to-monotone-increasing/

// time complexity: O(n)
// space complexity: O(n)

class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int n = s.size();

        // Initialize the prefix and suffix arrays to count zeroes and ones
        vector<int> countPrevOnes(n, 0);
        vector<int> countNextZeroes(n, 0);

        // count Prefix ones
        countPrevOnes[0] = (s[0] == '1');
        for (int i = 1; i < n; i++)
            countPrevOnes[i] = countPrevOnes[i - 1] + (s[i] == '1');

        // count Suffix Zeroes
        countNextZeroes[n - 1] = (s[n - 1] == '0');
        for (int i = n - 2; i > -1; i--)
            countNextZeroes[i] = countNextZeroes[i + 1] + (s[i] == '0');

        int minFlips = 1e9;
        for (int i = 0; i < n; i++)
        {

            int currFlips = 0;

            if (i - 1 > -1)
                currFlips += countPrevOnes[i - 1];

            if (i + 1 < n)
                currFlips += countNextZeroes[i + 1];

            minFlips = min(minFlips, currFlips);
        }
        return minFlips;
    }
};