// Problem Link: 2243. Calculate Digit Sum of a String

// Time Complexity:
//Space Complexity: 

class Solution
{
private:
    string helperFunction(string s, int k)
    {
        if (s.size() <= k)
        {
            return s;
        }
        int n = s.size();
        string res;
        string temp;
        for (int i = 0; i < n; i++)
        {
            if (temp.size() == k)
            {
                int sum = 0;
                for (int j = 0; j < k; j++)
                {
                    sum += temp[j] - '0';
                }
                res += to_string(sum);
                temp.clear();
            }
            temp.push_back(s[i]);
        }
        int x = temp.size();
        {
            int sum = 0;
            for (int j = 0; j < x; j++)
            {
                sum += temp[j] - '0';
            }
            res += to_string(sum);
            temp.clear();
        }
        return helperFunction(res, k);
    }

public:
    string digitSum(string s, int k)
    {
        string res = helperFunction(s, k);
        return res;
    }
};