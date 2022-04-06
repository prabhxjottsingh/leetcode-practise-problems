// Problem Link: https://leetcode.com/problems/3sum-with-multiplicity/

// Time Complexity: O(N^2)
// Space Compelxity: O(N)

class Solution
{
private:
    int mod = 1000000007;

public:
    int threeSumMulti(vector<int> &arr, int target)
    {
        int count = 0;
        int j, n = arr.size(), i;
        map<int, long long int> mp;
        for (i = 0; i < n; i++)
            mp[arr[i]]++;
        for (i = 0; i < 101; i++)
        {
            for (j = 0; j < 101; j++)
            {
                int k = target - i - j;
                if (k > 100 || k < 0)
                    continue;
                if ((i == j) && (k == j))
                    count = (count + (((mp[i]) * (mp[i] - 1) * (mp[j] - 2)) / 6)) % mod;
                else if ((i == j) && (j != k))
                    count = (count + ((mp[i] * (mp[j] - 1) / 2) * mp[k])) % mod;
                else if ((i < j) && (j < k))
                    count = (count + (mp[i] * mp[j] * mp[k])) % mod;
            }
        }
        return (count % mod);
    }
};