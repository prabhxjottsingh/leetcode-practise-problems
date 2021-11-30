//Problem Link: https://leetcode.com/problems/sort-colors/
//Tags: Array
//Difficulty: Medium
//Time Complexity: O(n)
//Space Complexity: Constant
//Will always be thankfull to CP :)

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int one = 0, two = 0, zero = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                zero++;
            else if (nums[i] == 1)
                one++;
            else
                two++;
        }
        for (int i = 0; i < zero; i++)
            nums[i] = 0;
        for (int i = zero; i < (one + zero); i++)
            nums[i] = 1;
        for (int i = (one + zero); i < (one + zero + two); i++)
            nums[i] = 2;
    }
};