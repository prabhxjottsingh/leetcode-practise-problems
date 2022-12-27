// Problem Link: https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/description/

// Time Complexity: O(n * log N)
// Space Complexity: O(N)

class Solution
{
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int addRocks)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0;
        int n = capacity.size();
        while (i < n)
        {
            pq.push(capacity[i] - rocks[i]);
            i += 1;
        }
        int count = 0;
        while (!pq.empty() && addRocks)
        {
            int diff = min(addRocks, pq.top());
            int topVal = pq.top();
            topVal -= diff;
            addRocks -= diff;
            if (topVal == 0)
                pq.pop(), count += 1;
            else
                break;
        }
        return count;
    }
};  