// Problem Link: 2231. Largest Number After Digit Swaps by Parity

// Space Complexity: O(1)
// Time Complexity: O(N)

class Solution
{
public:
    int largestInteger(int num)
    {
        string s = to_string(num);
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int x = s[i] - '0';
                int y = s[j] - '0';
                if ((x & 1) == (y & 1))
                {
                    if (x < y)
                        swap(s[i], s[j]);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res = res * 10 + (s[i] - '0');
        }
        return res;
    }
};