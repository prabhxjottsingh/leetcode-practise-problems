// Using Sliding Window Approach

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        map<char, int> mp1, mp2;
        int n = s1.length(), m = s2.length();
        if (m < n)
            return false;
        for (int i = 0; i < n; i++)
            mp1[s1[i]]++;
        for (int i = 0; i < n; i++)
            mp2[s2[i]]++;
        if (mp2 == mp1)
            return true;
        for (int i = n; i < m; i++)
        {
            if (mp2[s2[i - n]] == 1)
                mp2.erase(s2[i - n]);
            else
                mp2[s2[i - n]]--;
            mp2[s2[i]]++;
            if (mp2 == mp1)
                return true;
        }
        return false;
    }
};

// Time Compleixty: O(max(n,m))
// Space Compleixty: O(26) -> Constant Space
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int n = s1.size(), m = s2.size();
        if (m < n)
            return false;
        int hash1[27] = {0}, hash2[27] = {0};
        for (int i = 0; i < n; i++)
        {
            hash1[s1[i] - 'a'] += 1;
        }
        for (int i = 0; i < n; i++)
        {
            hash2[s2[i] - 'a'] += 1;
        }
        bool permuteFound = true;
        for (int i = 0; i < 26; i++)
        {
            if (hash1[i] != hash2[i])
            {
                permuteFound = false;
                break;
            }
        }
        if (permuteFound)
            return true;
        for (int i = n; i < m; i++)
        {
            hash2[s2[i - n] - 'a'] -= 1;
            hash2[s2[i] - 'a'] += 1;
            bool permuteFound = true;
            for (int j = 0; j < 26; j++)
            {
                if (hash1[j] != hash2[j])
                {
                    permuteFound = false;
                    break;
                }
            }
            if (permuteFound)
                return true;
        }
        return false;
    }
};
