// Problem Link: https://leetcode.com/problems/reorganize-string/description/

// Time Complexity: O(N * log N)
// Space Complexity: O(N)

class Solution
{
public:
    string reorganizeString(string s)
    {
        map<char, int> freq;
        for (auto &a : s)
            freq[a] += 1;
        for (auto &a : freq)
        {
            if (a.second > (s.size() + 1) / 2)
                return "";
        }
        priority_queue<pair<int, char>> pq;
        for (auto &a : freq)
            pq.push({a.second, a.first});
        int n = s.size();
        string resStr;
        pair<int, char> prev;
        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            resStr += curr.second, curr.first -= 1;
            if (prev.first > 0)
                pq.push(prev);
            prev = curr;
        }
        return resStr;
    }
};