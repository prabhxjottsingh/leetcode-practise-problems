// Problem Link: https://leetcode.com/problems/first-letter-to-appear-twice/
// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
public:
    char repeatedCharacter(string s)
    {
        set<char> st;
        for (auto &a : s)
        {
            if (st.count(a))
                return a;
            st.insert(a);
        }
        return 'a';
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    char repeatedCharacter(string s)
    {
        int arr[26];
        memset(arr, 0, sizeof(arr));
        char x = s[0];
        for (auto &a : s)
        {
            if (arr[a - 'a'] != 0)
                return a;
            arr[a - 'a'] = 1;
        }
        return x;
    }
};