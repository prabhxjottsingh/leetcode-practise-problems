// Probem Link: https://leetcode.com/problems/count-sorted-vowel-strings/

class Solution
{
private:
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    int helperFunction(int idx, string &temp, int n)
    {
        int count = 0;
        if (idx == n)
        {
            return 1;
        }
        for (int i = 0; i < 5; i++)
        {
            if (!temp.empty() && temp.back() > vowels[i])
                continue;
            temp.push_back(vowels[i]);
            count += helperFunction(idx + 1, temp, n);
            temp.pop_back();
        }
        return count;
    }

public:
    int countVowelStrings(int n)
    {
        int count = 0;
        string temp;
        count = helperFunction(0, temp, n);
        return count;
    }
};