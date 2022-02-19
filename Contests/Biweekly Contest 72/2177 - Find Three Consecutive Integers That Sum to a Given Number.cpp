// Problem Link: https://leetcode.com/contest/biweekly-contest-72/problems/find-three-consecutive-integers-that-sum-to-a-given-number/

// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution
{
public:
    vector<long long> sumOfThree(long long num)
    {
        vector<long long> ans;
        if (num == 0)
        {
            ans.push_back(-1);
            ans.push_back(0);
            ans.push_back(1);
        }
        else if ((num % 3 == 0))
        {
            ans.push_back(num / 3 - 1);
            ans.push_back(num / 3);
            ans.push_back(num / 3 + 1);
        }
        return ans;
    }
};