//Problem Link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
//Time Complexity: O(n)
//Space Complexity: O(n) -> Sets

class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        int n = nums.size();
        int maxx = 0, mask = 0;
        set<int> s;
        for (int i = 30; i >= 0; i--)
        {
            mask |= (1 << i);
            for (int j = 0; j < n; j++)
            {
                s.insert(mask & nums[j]);
            }
            int newMax = maxx | (1 << i);
            for (auto prefix : s)
            {
                if (s.count(newMax ^ prefix))
                {
                    maxx = newMax;
                    break;
                }
            }
            s.clear();
        }
        return maxx;
    }
};