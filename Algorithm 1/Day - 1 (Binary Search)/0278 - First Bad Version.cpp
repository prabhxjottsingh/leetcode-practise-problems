// Problem Link: https://leetcode.com/problems/first-bad-version/

// Time Complexity: O(N)
// Space Complexity: O(1)

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            if (isBadVersion(i))
                return i;
        }
        return (n + 1);
    }
};

// Time Complexity: O(Log N)
// Space Complexity: O(1)

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int low = 0, high = n;
        while (high > low)
        {
            int mid = low + (high - low) / 2;
            if (isBadVersion(mid))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return high;
    }
};