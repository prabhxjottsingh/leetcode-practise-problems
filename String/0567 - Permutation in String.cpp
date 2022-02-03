//Using Sliding Window Approach

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