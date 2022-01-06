//Tags: Medium
//Problem Link: https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
//Time Complexity:
//Space Complexity:

class Solution
{
private:
    bool isPrime(int x)
    {
        if (x < 2)
            return false;
        for (int i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
                return false;
        }
        return true;
    }

public:
    int countPrimeSetBits(int left, int right)
    {
        int countPrime = 0;
        for (int i = left; i <= right; i++)
        {
            int countSetBit = 0;
            for (int j = 0; j < 32; j++)
            {
                if ((i & (1 << j)))
                    countSetBit++;
            }
            if (isPrime(countSetBit))
                countPrime++;
        }
        return countPrime;
    }
};