// Problem Link: https://leetcode.com/problems/number-of-common-factors/

// Time Complexity: O(log(max(a, b)) + sqrt(min(a, b)))
// Space Complexity: O(1)

class Solution
{
private:
    int gcdFunc(int a, int b)
    {
        if (a == 0)
            return b;
        return gcdFunc(b % a, a);
    }

public:
    int commonFactors(int a, int b)
    {
        int gcd = gcdFunc(a, b);
        int count = 0;
        for (int i = 1; i <= sqrt(gcd); i++)
        {
            if (gcd % i == 0)
                count += 1, ((gcd / i != i) ? count += 1 : count += 0);
        }
        return count;
    }
};