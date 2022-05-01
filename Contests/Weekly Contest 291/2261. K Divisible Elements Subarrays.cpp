// Problem Link: https://leetcode.com/problems/k-divisible-elements-subarrays/

// Time Complexiy: O(N)
// Space Complexity: O(N)

#include <set>
class Solution
{
public:
    int countDistinct(vector<int> &nums, int k, int p)
    {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % p == 0)
                count++;
        }
        unordered_set<vector<int>> st;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            vector<int> vec;
            for (int j = i; j < n; j++)
            {
                if (nums[j] % p == 0)
                {
                    count++;
                }
                if (count > k)
                {
                    break;
                }
                vec.push_back(nums[j]);
                st.insert(vec);
            }
            if (count <= k)
                st.insert(vec);
        }
        return st.size();
    }
};