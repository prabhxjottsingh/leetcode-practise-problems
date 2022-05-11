// Problem Link: https://leetcode.com/problems/combinations/

class Solution
{
private:
    vector<vector<int>> finalAns;

    void helperFunction(int idx, vector<int> &digits, int k, vector<int> &temp)
    {
        if (idx >= digits.size() && temp.size() != k)
            return;
        if (temp.size() == k)
        {
            finalAns.push_back(temp);
            return;
        }
        temp.push_back(digits[idx]);
        helperFunction(idx + 1, digits, k, temp);
        temp.pop_back();
        helperFunction(idx + 1, digits, k, temp);
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> temp;
        vector<int> digits;
        for (int i = 0; i < n; i++)
        {
            digits.push_back(i + 1);
        }
        helperFunction(0, digits, k, temp);
        return finalAns;
    }
};