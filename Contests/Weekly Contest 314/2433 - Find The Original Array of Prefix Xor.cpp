// Problem Link: https://leetcode.com/problems/find-the-original-array-of-prefix-xor/

// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
public:
    vector<int> findArray(vector<int> &pref)
    {
        int n = pref.size();
        vector<int> arr(n);
        arr[0] = pref[0];
        for (int i = 1; i < n; i++)
        {
            int curr = pref[i];
            int prev = pref[i - 1];
            int newNum = 0;
            for (int i = 0; i < 32; i++)
            {
                if ((curr & (1 << i)))
                {
                    if (!(prev & (1 << i)))
                        newNum |= (1 << i);
                }
                else
                {
                    if ((prev & (1 << i)))
                        newNum |= (1 << i);
                }
            }
            arr[i] = newNum;
        }
        return arr;
    }
};