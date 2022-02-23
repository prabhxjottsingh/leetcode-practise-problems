// Problem Link: https://leetcode.com/problems/multiply-strings/

class Solution
{
private:
    string addStrings(string a, string b)
    {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        while (a.size() != b.size())
        {
            if (a.size() > b.size())
                b.push_back('0');
            else if (b.size() > a.size())
                a.push_back('0');
        }
        int n = a.size();
        string ans;
        int carry = 0;
        for (int i = 0; i < n; i++)
        {
            int x = a[i] - '0';
            int y = b[i] - '0';
            int z = x + y + carry;
            carry = 0;
            if (z > 9)
            {
                carry = z / 10;
            }
            z = z % 10;
            char ch = z + '0';
            ans.push_back(ch);
        }
        if (carry != 0)
        {
            char ch = carry + '0';
            ans.push_back(ch);
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        reverse(ans.begin(), ans.end());
        return ans;
    }

public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
        {
            string finalAns;
            finalAns.push_back('0');
            return finalAns;
        }
        string finalAns = "";
        int n = num1.size(), m = num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < n; i++)
        {
            string ans = "";
            int carry = 0;
            for (int j = 0; j < m; j++)
            {
                int x = num1[i] - '0';
                int y = num2[j] - '0';
                int multiplyXandY = x * y + carry;
                carry = multiplyXandY / 10;
                char ch = (multiplyXandY % 10) + '0';
                ans.push_back(ch);
            }
            if (carry != 0)
            {
                char ch = carry + '0';
                ans.push_back(ch);
            }
            reverse(ans.begin(), ans.end());
            int j = i;
            while (j > 0)
            {
                ans.push_back('0');
                j--;
            }
            finalAns = addStrings(finalAns, ans);
        }
        return finalAns;
    }
};