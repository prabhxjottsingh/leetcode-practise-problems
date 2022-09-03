// Problem Link: https://leetcode.com/problems/numbers-with-same-consecutive-differences/

// Time Complexity: O(2 ^ n)
// Space Complexity: o(1)

class Solution
{
private:
    bool countDigs(int x, int n)
    {
        int count = 0;
        while (x)
        {
            x /= 10;
            count += 1;
        }
        return count == n;
    }

    void func(int idx, int &n, int &k, int num, vector<int> &res)
    {
        if (idx == n)
        {
            if (!countDigs(num, n))
                return;
            res.push_back(num);
            return;
        }
        for (int i = 0; i < 10; i++)
        {
            int lastNum = num % 10;
            if ((abs(lastNum - i) == k) || (idx == 0 && i != 0))
                func(idx + 1, n, k, num * 10 + i, res);
        }
    }

public:
    vector<int> numsSameConsecDiff(int n, int k)
    {
        vector<int> res;
        int num = 0;
        func(0, n, k, num, res);
        return res;
    }
};