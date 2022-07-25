// Problem Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Time Complexity: O(log N)
// Space Complexit: O(1)

class Solution
{
private:
    int findPos(vector<int> &nums, int target, bool findingFirstPos)
    {
        int low = 0;
        int pos = -1;
        int high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                pos = mid;
                if (findingFirstPos)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return pos;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> resVec;
        resVec.push_back(findPos(nums, target, true));
        resVec.push_back(findPos(nums, target, false));
        return resVec;
    }
};



class Solution
{
private:
    int findPos(int low, int high, vector<int> &nums, int target, bool firstPos)
    {
        int res = -1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                res = mid;
                if (firstPos)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return res;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int firstPos = findPos(0, n - 1, nums, target, 1);
        int lastPos = findPos(0, n - 1, nums, target, 0);
        return {firstPos, lastPos};
    }
};