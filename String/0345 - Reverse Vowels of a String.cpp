// Problem Link: https://leetcode.com/problems/reverse-vowels-of-a-string/

// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    string reverseVowels(string s)
    {
        int n = s.size();
        set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int i = 0;
        int j = n - 1;
        while (i < j)
        {
            if (st.count(s[i]))
            {
                while (i < j && !st.count(s[j]))
                    j--;
                if (i < j)
                    swap(s[i], s[j]);
            }
            else if (st.count(s[j]))
            {
                while (i < j && !st.count(s[i]))
                    i++;
                if (i < j)
                    swap(s[i], s[j]);
            }
            i++;
            j--;
        }
        return s;
    }
};