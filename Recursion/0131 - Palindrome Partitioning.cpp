class Solution
{
private:
    bool isPal(string s)
    {
        int start = 0, end = s.size() - 1;
        while (start < end)
        {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    void func(int idx, int n, string &s, vector<vector<string>> &res, vector<string> &temp)
    {

        if (idx == n)
        {
            res.push_back(temp);
            return;
        }

        string str;
        for (int i = idx; i < n; i++)
        {
            str += s[i];
            if (isPal(str))
            {
                temp.push_back(str);
                func(i + 1, n, s, res, temp);
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        int n = s.size();
        vector<vector<string>> res;
        vector<string> temp;
        func(0, n, s, res, temp);
        return res;
    }
};