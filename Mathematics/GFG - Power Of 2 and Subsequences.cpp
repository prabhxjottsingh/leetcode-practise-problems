class Solution
{
private:
    const int mod = 1e9 + 7;

    bool isPowerOfTwo(long long num)
    {
        while (num % 2 == 0)
        {
            num /= 2;
        }
        return (num == 1);
    }

    long long helperFunc(int count)
    {
        long long ans = 1;
        while (count > 0)
        {
            ans *= 2;
            ans %= mod;
            count -= 1;
        }
        return ans;
    }

public:
    long long numberOfSubsequences(int N, long long A[])
    {
        int count = 0;
        for (int i = 0; i < N; i++)
        {
            if (isPowerOfTwo(A[i]))
                count += 1;
        }
        long long countRes = helperFunc(count) - 1;
        return countRes;
    }
};