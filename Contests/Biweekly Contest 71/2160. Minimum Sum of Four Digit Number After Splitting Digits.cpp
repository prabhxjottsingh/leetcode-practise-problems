// PRoblem Link: https://leetcode.com/contest/biweekly-contest-71/problems/minimum-sum-of-four-digit-number-after-splitting-digits/


//Time Complexity: O(1)
//Space Complexity: O(1)
class Solution
{
public:
    int minimumSum(int num)
    {
        string s = to_string(num);
        sort(s.begin(), s.end());
        cout << (s[0] - '0') * 10 << " ";
        int x = s[0] - '0';
        int y = s[1] - '0';
        int c = s[2] - '0';
        int b = s[3] - '0';
        // cout << x << " " << y << endl;
        return ((x * 10 + c) + (y * 10 + b));
    }
};