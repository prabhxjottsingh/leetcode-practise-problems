// Problem Link: https://leetcode.com/problems/sort-array-by-parity/

// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        vector<int> even, odd;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!(nums[i] & 1))
                even.push_back(nums[i]);
            else
                odd.push_back(nums[i]);
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i < even.size())
                nums[i] = even[i];
            else
                nums[i] = odd[i - even.size()];
        }
        return nums;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)

//No need to sort the array just bring even integers at front and odd integers after that

class Solution
{
private:
    void swap(vector<int> &v, int x, int y)
    {
        int temp = v[x];
        v[x] = v[y];
        v[y] = temp;
    }

public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0, j = n - 1;
        while (i < j)
        {
            if (nums[i] % 2 > nums[j] % 2)
            {
                swap(nums, i, j);
            }
            if (nums[i] % 2 == 0)
                i++;
            if (nums[j] % 2 != 0)
                j--;
        }
        return nums;
    }
};
