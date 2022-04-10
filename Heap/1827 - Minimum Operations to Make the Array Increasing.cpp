// Problem Link: https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/

//Time Complexity: O(N)
//Space Complexity: O(N)

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        priority_queue<int> pq;
        int operations = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!pq.empty() && pq.top() >= nums[i])
            {
                operations += pq.top() - nums[i] + 1;
                nums[i] = pq.top() + 1;
            }
            pq.push(nums[i]);
        }
        return operations;
    }
};