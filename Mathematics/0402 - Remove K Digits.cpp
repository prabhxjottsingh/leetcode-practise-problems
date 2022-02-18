// Problem Link: https://leetcode.com/problems/remove-k-digits/

// Time Complexity: O(k*n) -> because of the use of erase function
// Space Complexity: O(constant)

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        while (k > 0)
        {
            int n = num.size();
            int i = 0;
            while ((i < n - 1) && (num[i] <= num[i + 1]))
                i++;
            num.erase(i, 1);
            k--;
        }
        string ans;
        bool nonZero = false;
        for (int i = 0; i < num.size(); i++)
        {
            if ((num[i] != '0') || (nonZero))
            {
                ans.push_back(num[i]);
                nonZero = true;
            }
        }
        if (ans.size() == 0)
            return "0";
        return ans;
    }
};


//Time Complexity: O(n)
//Space Complexity: O(n) -> using stacks

