class Solution
{
private:
    bool isValid(string &str)
    {
        if ((str.size() > 1 && str[0] == '0') || stoi(str) > 255)
            return false;
        return true;
    }

    void func(int idx, string &s, string temp, vector<string> &res, int dots)
    {
        if (idx == s.size() && dots == 4)
        {
            temp.pop_back();
            res.push_back(temp);
            return;
        }
        if (idx == s.size() || dots == 4)
            return;
        for (int i = 1; i <= 3 && idx + i <= s.size(); i++)
        {
            string strTemp = s.substr(idx, i);
            if (isValid(strTemp))
            {
                func(idx + i, s, temp + strTemp + '.', res, dots + 1);
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> res;
        func(0, s, "", res, 0);
        return res;
    }
};