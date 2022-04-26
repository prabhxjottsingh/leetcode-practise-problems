// Problem Link: https://leetcode.com/problems/count-the-hidden-sequences/

// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    int numberOfArrays(vector<int> &differences, int lower, int upper)
    {
        long long int peekVal = INT_MIN, minVal = INT_MAX;
        long long int tempVal = 0;
        for (auto &a : differences)
        {
            tempVal += a;
            peekVal = max(peekVal, tempVal);
            minVal = min(minVal, tempVal);
        }
        long long int left = max(lower * 1ll, lower - minVal);
        long long int right = min(upper * 1ll, upper - peekVal);
        long long int count = right - left + 1;
        return max(0ll, count);
    }
};