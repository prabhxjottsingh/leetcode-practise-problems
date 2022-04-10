// Problem Link: https://leetcode.com/problems/maximum-product-after-k-increments/

// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
private:
    int mod = 1e9 + 7;

public:
    int maximumProduct(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
        }
        while (k--)
        {
            int x = pq.top();
            pq.pop();
            pq.push(x + 1);
        }
        long long int prod = 1;
        while (!pq.empty())
        {
            prod = (prod * pq.top() % mod);
            pq.pop();
        }
        return prod;
    }
};