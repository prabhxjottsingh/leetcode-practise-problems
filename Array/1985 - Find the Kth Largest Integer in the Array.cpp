//Problem Link: https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/
//Tags: Array
//Difficulty: Medium
//Time Complexity: O(n logn)

class Solution
{
private:
    static bool comparator(const string a, const string b)
    {
        if (a.size() < b.size())
            return true;
        else if (a.size() > b.size())
            return false;
        return (a < b);
    }

public:
    string kthLargestNumber(vector<string> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end(), comparator);
        return nums[n - k];
    }
};