// Problem Link: https://leetcode.com/problems/minimum-operations-to-halve-array-sum/submissions/

// Time Complexity: O(N * log N)
// Space Complexity: O(N)

class Solution
{
public:
    int halveArray(vector<int> &nums)
    {
        priority_queue<double> pq;
        double sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
            sum += nums[i];
        }
        int countOperations = 0;
        double reqSum = sum / 2;
        while (sum > reqSum)
        {
            float x = pq.top();
            pq.pop();
            sum -= x;
            x /= 2;
            sum += x;
            pq.push(x);
            countOperations++;
        }
        return countOperations;
    }
};