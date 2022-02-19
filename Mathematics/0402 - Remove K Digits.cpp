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

// Time Complexity: O(n)
// Space Complexity: O(n) -> using stacks

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<char> st;
        string ans;
        int k2 = k;
        int n = num.size();
        st.push(num[0]);
        for (int i = 1; i < n; i++)
        {
            while ((!st.empty()) && (st.top() > num[i]) && (k > 0))
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while ((!st.empty()))
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        string finalAns;
        bool nonZero = false;
        for (int i = 0; i < ans.size() && (i < (n - k2)); i++)
        {
            if (ans[i] != '0' || nonZero)
            {
                finalAns += ans[i];
                nonZero = true;
            }
        }
        if (finalAns.size() == 0)
            return "0";
        return finalAns;
    }
};
