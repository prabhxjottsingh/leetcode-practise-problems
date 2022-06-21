class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int n = heights.size();
        vector<int> res;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i <= n - 2; i++)
        {
            if (heights[i] < heights[i + 1])
            {
                int diff = heights[i + 1] - heights[i];
                pq.push(diff);
            }
            if (pq.size() > ladders)
            {
                bricks -= pq.top();
                pq.pop();
                if (bricks < 0)
                    return i;
            }
        }
        return (n - 1);
    }
};