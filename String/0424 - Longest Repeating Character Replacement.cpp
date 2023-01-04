// Problem Link: https://leetcode.com/problems/longest-repeating-character-replacement/description/

// time Complexity: O(N * 26)
// Space Complexity: O(1)
class Solution
{
private:
    int calMaxLen(string &s, int k, char &ch)
    {
        int i = 0;
        int j = 0;
        int n = s.size();
        int maxLen = 0;
        while (j < n)
        {
            while (i < n && (k || s[i] == ch))
            {
                if (s[i] != ch)
                    k--;
                i++;
            }
            maxLen = max(maxLen, i - j);
            if (s[j] != ch)
                k++;
            j++;
        }
        return maxLen;
    }

public:
    int characterReplacement(string s, int k)
    {
        int maxLen = 0;
        for (char ch = 'A'; ch <= 'Z'; ch++)
            maxLen = max(maxLen, calMaxLen(s, k, ch));
        return maxLen;
    }
};

// binary search + sliding window
// Time ComplexitY: O(n * log N * 26)
// space Complexity: O(26)
class Solution
{
private:
    bool isPossible(string &s, int k, int windowSz)
    {
        int n = s.size();
        int freq[26];
        memset(freq, 0, sizeof(freq));
        for (int i = 0; i < windowSz; i++)
            freq[s[i] - 'A'] += 1;
        bool isLenPos = ((k + *max_element(freq, freq + 26)) >= windowSz);
        if (isLenPos)
            return true;
        for (int i = windowSz; i < n; i++)
        {
            freq[s[i - windowSz] - 'A'] -= 1;
            freq[s[i] - 'A'] += 1;
            isLenPos |= ((k + *max_element(freq, freq + 26)) >= windowSz);
            if (isLenPos)
                return true;
        }
        return false;
    }

public:
    int characterReplacement(string s, int k)
    {
        int low = 0;
        int high = s.size();
        int resLen = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isPossible(s, k, mid))
                low = mid + 1, resLen = mid;
            else
                high = mid - 1;
        }
        return resLen;
    }
};