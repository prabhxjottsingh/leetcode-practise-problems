//Tags: String
//Difficulty: Easy
//Problem Link: https://leetcode.com/problems/sorting-the-sentence/
//Time Complexity: O(n)   (time complexity of push_back function is O(1))

//Break the problem into parts, and then try to think of the solution with the help of all the knowledge you have of the particular topic\

class Solution
{
public:
    string sortSentence(string s)
    {
        int n = s.length();
        int m = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (isdigit(s[i]))
                m = max(m, s[i] - '0');
        }
        vector<string> v(m);
        bool flag = false;
        string a = "";
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
                continue;
            int index;
            if (isdigit(s[i]) || (i == 0))
            {
                if (i == 0)
                    a.push_back(s[i]);
                if (flag)
                {
                    reverse(a.begin(), a.end());
                    v[index - 1] = a;
                }
                index = s[i] - '0';
                flag = true;
                a = "";
            }
            else
            {
                a.push_back(s[i]);
            }
        }
        string ans;
        int z = v.size();
        for (int i = 0; i < z; i++)
        {
            ans += (v[i]);
            if (i < z - 1)
                ans += " ";
        }
        return ans;
    }
};