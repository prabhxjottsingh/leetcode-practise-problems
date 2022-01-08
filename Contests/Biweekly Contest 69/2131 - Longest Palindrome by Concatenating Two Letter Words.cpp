//Tags: MEdium, String
//Problem Link: https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/
//Time Complexity: O(N)
//SPace Complexity: O(N) -> taken the help of map data structure

class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        map<string, int> mp;
        for (int i = 0; i < words.size(); i++)
            mp[words[i]]++;
        int len = 0, extra = false;
        map<string, int>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++)
        {
            string s1 = it->first;
            int f1 = it->second;
            string s2 = s1;
            reverse(s2.begin(), s2.end());

            if (mp.find(s2) != mp.end())
            { // checking if reverse of current string exist or not
                int f2 = mp[s2];

                if (s1 == s2)
                {
                    len += (f1 > 1 ? (f1 / 2) * 4 : 0);
                    if (f1 % 2 == 1)
                        extra = true; // ['dd','aa',dd','bb'] --> we can use 1 of the pair occuring once as mid of our palindrome
                }
                else
                {
                    len += min(f1, f2) * 4;
                }

                mp.erase(s2);
            }
            mp.erase(s1);
        }

        if (extra)
            len += 2;

        return len;
    }
};