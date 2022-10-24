// Problem Link: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

// Time Complexity: O(2 ^ N)
// Space Complexity: O(N) + O(N) (Recursion Stack)

class Solution
{
private:
    void func(int idx, int n, vector<pair<int, int>> &pr, int len, int &maxLen, int num)
    {
        if (idx == n)
        {
            maxLen = max(maxLen, len);
            return;
        }
        if ((num & pr[idx].second) == 0)
            func(idx + 1, n, pr, len + pr[idx].first, maxLen, (num | pr[idx].second));
        func(idx + 1, n, pr, len, maxLen, num);
    }

public:
    int maxLength(vector<string> &arr)
    {
        vector<pair<int, int>> pr;
        for (auto &a : arr)
        {
            int num = 0;
            bool notInsert = false;
            for (int i = 0; i < (int)a.size(); i++)
            {
                if ((num & (1 << (a[i] - 'a'))) != 0)
                {
                    notInsert = true;
                    break;
                }
                num |= (1 << (a[i] - 'a'));
            }
            if (!notInsert)
                pr.push_back({a.size(), num});
        }
        int maxLen = 0;
        func(0, (int)pr.size(), pr, 0, maxLen, 0);
        return maxLen;
    }
};