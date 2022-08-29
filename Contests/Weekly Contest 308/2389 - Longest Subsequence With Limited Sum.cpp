// Problem Link: https://leetcode.com/problems/longest-subsequence-with-limited-sum/

// Time Complexity: O(N * log N)
// Space Complexity: O(N)

class Solution
{
private:
    int binarySearch(int target, vector<int> &sum)
    {
        int low = 0;
        int high = sum.size() - 1;
        int res = sum.size();
        if (sum[0] > target)
            return 0;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (sum[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                res = mid;
                low = mid + 1;
            }
        }
        return res + 1;
    }

public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        vector<int> sum;
        sort(nums.begin(), nums.end());
        for (auto &a : nums)
        {
            if (sum.empty())
                sum.push_back(a);
            else
                sum.push_back(sum.back() + a);
        }
        vector<int> res;
        for (auto &a : queries)
        {
            res.push_back(binarySearch(a, sum));
        }
        return res;
    }
};