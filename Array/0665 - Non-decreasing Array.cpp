class Solution
{
private:
    bool isSorted(vector<int> &nums)
    {
        vector<int> temp = nums;
        sort(nums.begin(), nums.end());
        return (temp == nums);
    }

public:
    bool checkPossibility(vector<int> &nums)
    {
        bool found = false;
        int n = nums.size();
        vector<int> numsTwo = nums;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i + 1] < nums[i])
            {
                if (found)
                    return false;
                nums[i] = nums[i + 1];
                numsTwo[i + 1] = numsTwo[i];
                found = true;
            }
        }
        if (isSorted(nums) || isSorted(numsTwo))
            return true;
        return false;
    }
};