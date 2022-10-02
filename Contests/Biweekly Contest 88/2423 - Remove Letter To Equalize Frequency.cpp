// Problem Link: https://leetcode.com/problems/remove-letter-to-equalize-frequency/

// Time complexity: O(N * log N)
// Space Complexity: O(N)

class Solution
{
public:
    bool equalFrequency(string word)
    {
        map<char, int> freq;
        for (auto &a : word)
            freq[a] += 1;
        map<int, int> countFreq;
        for (char ch = 'a'; ch <= 'z'; ++ch)
        {
            if (freq.count(ch))
                countFreq[freq[ch]] += 1;
        }
        for (auto &a : countFreq)
            cout << a.first << " -> " << a.second << endl;
        map<int, int> initFreq = countFreq;
        for (auto &a : word)
        {
            int removedNum = freq[a];
            int addedNum = removedNum - 1;
            if (countFreq[removedNum] == 1)
                countFreq.erase(removedNum);
            else
                countFreq[removedNum] -= 1;
            if (addedNum != 0)
                countFreq[addedNum] += 1;
            if (countFreq.size() == 1)
                return true;
            cout << a << " -> " << countFreq.size() << endl;
            for (auto &a : countFreq)
                cout << a.first << " -> " << a.second << endl;
            cout << endl;
            countFreq = initFreq;
        }
        for (auto &a : countFreq)
            cout << a.first << " " << a.second << endl;
        return false;
    }
};