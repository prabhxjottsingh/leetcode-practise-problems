// Problem Link: https://leetcode.com/problems/last-stone-weight/

// Space Complexity: O(N)
// Time Complexity: O(N * log N) -> TC of inserting and popping a value from heap ds is O(Log N)

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq;
        int n = stones.size();
        for (int i = 0; i < n; i++)
        {
            pq.push(stones[i]);
        }
        while (pq.size() > 1)
        {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if (x != y)
                pq.push(y - x);
        }
        if (pq.empty())
            return 0;
        return pq.top();
    }
};