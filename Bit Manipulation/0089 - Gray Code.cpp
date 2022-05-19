// Problem Link: https://leetcode.com/problems/gray-code/

//Time Complexity: O(N)

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> res;
        int size = pow(2, n) - 1;
        for (int i = 0; i <= size; i++)
        {
            int x = (i ^ (i >> 1));
            res.push_back(x);
        }
        return res;
    }
};