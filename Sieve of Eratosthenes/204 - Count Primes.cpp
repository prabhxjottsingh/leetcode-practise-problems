//Tags: Sieve Algorithm, Medium
//Problem Link: https://leetcode.com/problems/count-primes/
//Time Complexity:
//Space Complexity:

class Solution
{
public:
    int countPrimes(int n)
    {
        vector<bool> check(n + 1, true);
        check[0] = false;
        check[1] = false;
        for (int i = 2; i * i <= n; i++)
        {
            if (check[i] == false)
                continue;
            int j = i * i;
            while (j <= n)
            {
                check[j] = false;
                j = j + i;
            }
        }

        int count = 0;
        for (int i = 1; i < n; i++)
            if (check[i])
                count++;

        return count;
    }
};