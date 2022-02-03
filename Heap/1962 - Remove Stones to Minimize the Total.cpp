//Problem Link: https://leetcode.com/problems/remove-stones-to-minimize-the-total/
//Time Complexity: O(n)
//Space Complexity: O(n)

class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        priority_queue<int> pq;
        int n = piles.size();
        for (int i = 0; i < n; i++)
        {
            pq.push(piles[i]);
        }
        while (k--)
        {
            int x = pq.top();
            x = x - floor(x / 2);
            pq.pop();
            pq.push(x);
        }
        int sum = 0;
        while (!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};