// Problem Link: https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/submissions/

// Time Complexity: O(N ^ 2)
// Space Complexity: O(N)

class Solution
{
private:
    static bool comp(const string &a, const string &b)
    {
        if (a.size() == b.size())
            return (a > b);
        return (a.size() > b.size());
    }

public:
    string removeDigit(string number, char digit)
    {
        int n = number.size();
        vector<int> pos;
        for (int i = 0; i < n; i++)
        {
            if (number[i] == digit)
                pos.push_back(i);
        }
        vector<string> v;
        for (int i = 0; i < pos.size(); i++)
        {
            string temp;
            for (int j = 0; j < number.size(); j++)
            {
                if (j != pos[i])
                    temp.push_back(number[j]);
            }
            v.push_back(temp);
        }
        sort(v.begin(), v.end(), comp);
        return v[0];
    }
};