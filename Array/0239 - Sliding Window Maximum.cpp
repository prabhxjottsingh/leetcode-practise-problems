//Tags: hard
//Problem Link: https://leetcode.com/problems/sliding-window-maximum/
//Time Complexity:
//Space Complexity: O(k) -> bcs of sets;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        int n = nums.size();
        multiset<int, greater<int>> maxNum;
        for (int i = 0; i < k; i++)
        {
            maxNum.insert(nums[i]);
        }
        ans.push_back(*maxNum.begin());
        for (int i = k; i < n; i++)
        {
            maxNum.erase(maxNum.find(nums[i - k]));
            maxNum.insert(nums[i]);
            ans.push_back(*maxNum.begin());
        }
        return ans;
    }
};