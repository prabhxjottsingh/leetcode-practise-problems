// Problem Link: https://leetcode.com/problems/alternating-digit-sum/description/

// time Complexity: O(log(n))
// space Complexity:O(log(n)) -> Recursion

class Solution
{
private:
    int count(int n)
    {
        if (!n)
            return 0;
        return 1 + count(n / 10);
    }

    int func(int n, bool flag)
    {
        if (!n)
            return 0;
        if (!flag)
            return n % 10 + func(n / 10, 1);
        return -(n % 10) + func(n / 10, 0);
    }

public:
    int alternateDigitSum(int n)
    {
        int countDigs = count(n);
        bool flag = 1;
        if (countDigs & 1)
            flag = 0;
        int sum = func(n, flag);
        return sum;
    }
};