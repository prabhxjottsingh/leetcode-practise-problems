// Problem Link: https://leetcode.com/problems/sum-of-even-numbers-after-queries/

// Time Complexity: O(n)
// space complexity: O(1)

class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        int evenSum = 0;
        for (auto &a : nums)
        {
            if (!(a & 1))
                evenSum += a;
        }
        vector<int> resVec;
        for (auto &a : queries)
        {
            int val = a[0];
            int idx = a[1];
            if (!(nums[idx] & 1))
                evenSum -= nums[idx];
            nums[idx] += val;
            if (!(nums[idx] & 1))
                evenSum += nums[idx];
            resVec.push_back(evenSum);
        }
        return resVec;
    }
};
