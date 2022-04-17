// Problem Link: https://leetcode.com/problems/search-a-2d-matrix-ii/

// Time Complexity: O(N * M * log M)
// Space Complexity:  O(1)

class Solution
{
private:
    bool binarySearch(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        if (target < nums[left] || target > nums[right])
            return false;
        while (left <= right)
        {
            int mid = left + ((right - left) / 2);
            if (nums[mid] == target)
                return true;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }

public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        if (matrix[n - 1][matrix[0].size() - 1] < target)
            return false;
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            found |= binarySearch(matrix[i], target);
            if (found == 1)
                return found;
        }
        return found;
    }
};