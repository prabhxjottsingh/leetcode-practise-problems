// Naive Approach:

// Time Complexity: O(N * M + N * M * log (N * M))
// Space Complexity: O(N * M)
class Solution
{
public:
    int median(vector<vector<int>> &matrix, int R, int C)
    {
        vector<int> nums;
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                nums.push_back(matrix[i][j]);
            }
        }
        sort(nums.begin(), nums.end());
        return nums[R * C / 2];
    }
};

// Optimised Approach
// time Complexity: O(log 2000 * R * log C)
// Space Complexity: O(1)

class Solution
{
private:
    int countSmallerThanMid(vector<int> &nums, int k)
    {
        int count = 0;
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            if (nums[mid] <= k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }

public:
    int median(vector<vector<int>> &matrix, int R, int C)
    {
        int low = 0;
        int high = 2000;
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            int count = 0;
            for (int i = 0; i < R; i++)
            {
                count += countSmallerThanMid(matrix[i], mid);
            }
            if (count <= R * C / 2)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};