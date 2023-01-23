// problem Link: https://leetcode.com/problems/apply-bitwise-operations-to-make-strings-equal/description/

// time Complexitty: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    bool makeStringsEqual(string s, string t)
    {
        bool oneS = 0;
        bool oneT = 0;
        for (auto &a : s)
            if (a == '1')
                oneS = 1;
        for (auto &a : t)
            if (a == '1')
                oneT = 1;
        return oneS == oneT;
    }
};