// Problem Link: https://leetcode.com/contest/biweekly-contest-72/problems/maximum-split-of-positive-even-integers/

//Space Complexity: O(1)
//Time Complexity: O(sqrt(n))

class Solution
{
public:
    vector<long long> maximumEvenSplit(long long finalSum)
    {
        vector<long long> ans;
        if (finalSum & 1)
            return ans;
        long long x = 2;
        while ((finalSum - x) >= x + 2)
        {
            ans.push_back(x);
            finalSum -= x;
            x += 2;
        }
        ans.push_back(finalSum);
        return ans;
    }
};