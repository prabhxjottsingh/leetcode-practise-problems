//Problem Link: https://practice.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k1259/1

class Solution
{
public:
    int longSubarrWthSumDivByK(int arr[], int n, int k)
    {
        int maxLen = 0;
        map<int, int> mp;
        mp[0] = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum = (((sum + arr[i]) % k) + k) % k; //as the sum can be negative so we are taking modulo twice
            if (mp.count(sum))
            {
                maxLen = max(maxLen, i - mp[sum]);
            }
            else
            {
                mp[sum] = i;
            }
        }
        return maxLen;
    }
};