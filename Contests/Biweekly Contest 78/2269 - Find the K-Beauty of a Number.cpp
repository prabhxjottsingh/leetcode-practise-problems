// Problem Link: https://leetcode.com/problems/find-the-k-beauty-of-a-number/

// Time Complexity: O(n*k)
// Space Complexity: o(1)

class Solution
{
private:
    bool isDivisible(string s, int n)
    {
        reverse(s.begin(), s.end());
        while (!s.empty() && s.back() == '0')
            s.pop_back();
        if (s.empty())
            return false;
        reverse(s.begin(), s.end());
        int x = stoi(s);
        if (n % x == 0)
            return true;
        return false;
    }

public:
    int divisorSubstrings(int num, int k)
    {
        string s = to_string(num);
        int n = s.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            string temp;
            for (int j = i; j < min(k + i, n); j++)
            {
                temp += s[j];
            }
            if ((temp.size() == k) && isDivisible(temp, num))
                count++;
        }
        return count;
    }
};