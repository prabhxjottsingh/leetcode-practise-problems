// Problem Link: https://practice.geeksforgeeks.org/problems/minimum-time-to-fulfil-all-orders/1

// time Complexity: O(n * log N)
// Space Cpomplexity: O(1)

class Solution
{
public:
    int findMinTime(int N, vector<int> &A, int L)
    {
        auto isPossible = [](int target, vector<int> nums, int N)
        {
            int n = nums.size();
            int countBurgs = 0;
            for (int i = 0; i < n; i++)
            {
                int temp = 0;
                int timeTaken = nums[i];
                while (temp + timeTaken <= target)
                {
                    countBurgs += 1;
                    temp += timeTaken;
                    timeTaken += nums[i];
                }
            }
            return countBurgs >= N;
        };
        int low = 1;
        int high = 1e8 + 7;
        int res = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (isPossible(mid, A, N))
            {
                high = mid - 1;
                res = mid;
            }
            else
                low = mid + 1;
        }
        return res;
    }
};