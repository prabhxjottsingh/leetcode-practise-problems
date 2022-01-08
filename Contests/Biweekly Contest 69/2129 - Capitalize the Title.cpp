//Tags: Easy, String
//Problem Link: https://leetcode.com/problems/capitalize-the-title/
//Time Compelxtiy: o(N) -> we are tranversing though the array only one time
//Space Complexity: O(n) (created answer array)

class Solution
{
public:
    string capitalizeTitle(string title)
    {
        string ans;
        int count = 1;
        int n = title.size();
        for (int i = 0; i < n; i++)
        {
            if (title[i] == ' ')
            {
                if (count < 4)
                {
                    ans.push_back(' ');
                    count = 0;
                }
                else
                {
                    ans.push_back(' ');
                    if (ans[i - count + 1] >= 65 && ans[i - count + 1] <= 90)
                        count = 0;
                    else
                        ans[i - count + 1] = ans[i - count + 1] - 32;
                    count = 0;
                }
                count++;
            }
            else
            {
                count++;
                if (title[i] >= 65 && title[i] <= 90)
                    ans.push_back(title[i] + 32);
                else
                    ans.push_back(title[i]);
            }
        }
        if (count >= 4)
        {
            if (ans[n - count + 1] >= 65 && ans[n - count + 1] <= 90)
                count++;
            else
                ans[n - count + 1] = ans[n - count + 1] - 32;
        }
        return ans;
    }
};