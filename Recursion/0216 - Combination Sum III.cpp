// Problem Link: https://leetcode.com/problems/combination-sum-iii/

// Space Complexity: O(1)
// Time Complexity: O(2 ^ 9)

class Solution
{
private:
    void helperFunction(int i, vector<int> &digits, int k, int n, vector<int> &temp, vector<vector<int>> &finalAns)
    {
        if (temp.size() == k)
        {
            int sum = 0;
            int size = min(k, (int)temp.size());
            for (int i = 0; i < size; i++)
            {
                sum += temp[i];
            }
            if (sum == n && temp.size() == k)
                finalAns.push_back(temp);
            return;
        }
        if (i >= digits.size())
            return;
        temp.push_back(digits[i]);
        helperFunction(i + 1, digits, k, n, temp, finalAns);
        temp.pop_back();
        helperFunction(i + 1, digits, k, n, temp, finalAns);
        // return;
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> finalAns;
        vector<int> temp;
        vector<int> digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        helperFunction(0, digits, k, n, temp, finalAns);
        return finalAns;
    }
};