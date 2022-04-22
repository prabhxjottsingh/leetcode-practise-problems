// Tags: String
// Difficulty: Medium
// Problem Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Time Complexity: not sure about this one, will update about this soon

// Concept: we will iterate thought each element of the string

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int current = 0, start = 0, maxLength = 0;
        map<char, int> mp; // map to count the characters in substrings
        for (; current < n; current++)
        {
            mp[s[current]]++;          // update the presence of the elements
            while (mp[s[current]] > 1) // if current element appears more than once
            {
                mp[s[start++]]--; // will reach the point where the first presence of the elment is discovered
            }
            int currentLength = current - start + 1; // length of the substring with every element having presence once
            maxLength = max(maxLength, currentLength);
        }
        return maxLength;
    }
};

// O(n) Solution

class Solution
{
public:
    int longestUniqueSubsttr(string S)
    {
        // code
        int n = S.length();
        map<char, int> mp;
        int current = 0, start = 0, maxLength = 0;
        for (; current < n; current++)
        {
            if (mp.find(S[current]) != mp.end())
            {
                start = max(start, mp[S[current]] + 1); // this would make the start pointer to go to the next position of the repeated element first appearnce (P.S: Earlier we were using while loop for this purpose, but this time we have made it looks easy)
            }
            mp[S[current]] = current;
            int currentLength = current - start + 1;
            maxLength = max(maxLength, currentLength);
        }
        return maxLength;
    }
};

//O(N) Solution with O(N) Space Taken because of unoredered map used

class Solution
{
private:
    void updateMap(unordered_map<char, int> &mp, char ch)
    {
        if (mp[ch] == 1)
            mp.erase(ch);
        else
            mp[ch]--;
    }

    int max(int a, int b)
    {
        if (a > b)
            return a;
        return b;
    }

public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> mp;
        int n = s.size(), i, window = 0, mapSize;
        for (int i = 0; i < n; i++)
        {
            mp[s[i]]++;
            mapSize = mp.size();
            if (mapSize < i + 1)
            {
                mp[s[i]]--;
                window = i;
                break;
            }
        }
        mapSize = mp.size();
        int maxLen = 0;
        maxLen = max(maxLen, mapSize);
        int startWindow = 0;
        for (int i = window; i < n; i++)
        {
            mp[s[i]]++;
            mapSize = mp.size();
            while ((mapSize) < (i - startWindow + 1))
            {
                updateMap(mp, s[startWindow]);
                startWindow++;
                mapSize = mp.size();
            }
            maxLen = max(maxLen, mapSize);
        }
        return maxLen;
    }
};