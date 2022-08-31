// Problem Link: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/

// Time Complexity: O(2 ^ (n))
// Space Complexity: O(1)

class Solution
{
private:
    void func(int idx, int n, int k, string &res, string temp, int &count)
    {
        if (idx == n)
        {
            count += 1;
            if (count == k)
                res = temp;
            return;
        }
        for (char ch = 'a'; ch <= 'c'; ch++)
        {
            if (temp.size() > 0 && temp.back() == ch)
                continue;
            func(idx + 1, n, k, res, temp + ch, count);
        }
    }

public:
    string getHappyString(int n, int k)
    {
        string res;
        string temp;
        int count = 0;
        func(0, n, k, res, temp, count);
        return res;
    }
};