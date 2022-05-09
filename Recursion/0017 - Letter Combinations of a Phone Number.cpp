class Solution
{
private:
    map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };

    void helperFunction(int i, string digits, string &temp, vector<string> &finalAns)
    {
        if (temp.size() == digits.size())
        {
            finalAns.push_back(temp);
            return;
        }
        for (auto &c : mp[digits[i]])
        {
            temp += c;
            helperFunction(i + 1, digits, temp, finalAns);
            temp.pop_back();
        }
        return;
    }

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> finalAns;
        if (digits.size() == 0)
            return finalAns;
        string temp;
        helperFunction(0, digits, temp, finalAns);
        return finalAns;
    }
};