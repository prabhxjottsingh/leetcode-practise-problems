// Problem Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Time Complexity:O(n)
// Space Complexity: O(1)

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0;
        for (auto n : nums)
        {
            if (i < 2 || nums[i - 2] < n)
                nums[i++] = n;
        }
        return i;
    }
};


// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int k = 0, n = nums.size();
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        nums.clear();
        for (auto a : mp)
        {
            if (a.second > 2)
            {
                k += 2;
                int x = 2;
                while (x--)
                    nums.push_back(a.first);
            }
            else
            {
                k += a.second;
                while (a.second--)
                    nums.push_back(a.first);
            }
        }
        return k;
    }
};