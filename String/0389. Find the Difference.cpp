// Problem Link: https://leetcode.com/problems/find-the-difference/

// Time Complexity: O(n + n*log n)
// Space Complexoty: O(1)
class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (t[i] != s[i])
                return t[i];
        }
        return t[n];
    }
};

// Time Compleixity: O(n)
// Space Compleoxty: O(1)
class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        int a = 0, b = 0;
        for (auto p : s)
            a += p;
        for (auto p : t)
            b += p;
        return abs(a - b);
    }
};


//XOR wil become zero if a single character appears twice
// Time Complexity: O(n)
// Space Compleixty: O(1)
class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        int x = 0;
        for (auto a : s)
            x ^= a;
        for (auto a : t)
            x ^= a;
        return x;
    }
};