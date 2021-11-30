//Problem Link: https://leetcode.com/problems/product-of-array-except-self/
//Tags: Array
//Difficulty: Medium
//Time Complexity: O(n)
//Took a bit of non-accepted submissions but after a while was able to do this in the O(n) time complxity,
//took a bit if time in thinking of the approach




class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> ans;
        bool flag = 0;
        int nonZero = 0, prod = 1, count = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                prod = prod * nums[i];
                nonZero++;
            }
            if (nums[i] == 0)
                count++;
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                nonZero--;
                if (count > 0)
                    ans.push_back(0);
                else
                    ans.push_back(prod / nums[i]);
                nonZero++;
            }
            else
            {
                count--;
                if (count > 0)
                    ans.push_back(0);
                else
                    ans.push_back(prod);
                count++;
            }
        }
        return ans;
    }
};