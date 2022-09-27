// Problem Link: https://leetcode.com/problems/push-dominoes/

// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
public:
    string pushDominoes(string s)
    {
        int n = s.size();
        vector<int> leftDominoIdx(n, 0);
        vector<int> rightDominoIdx(n, 0);
        if (s[0] == 'R')
            rightDominoIdx[0] = 0;
        else
            rightDominoIdx[0] = -1e9;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == 'R')
                rightDominoIdx[i] = i;
            else if (s[i] == '.')
                rightDominoIdx[i] = rightDominoIdx[i - 1];
            else
                rightDominoIdx[i] = -1e9;
        }
        if (s[n - 1] == 'L')
            leftDominoIdx[n - 1] = n - 1;
        else
            leftDominoIdx[n - 1] = 1e9;
        for (int i = n - 2; i > -1; i--)
        {
            if (s[i] == 'L')
                leftDominoIdx[i] = i;
            else if (s[i] == '.')
                leftDominoIdx[i] = leftDominoIdx[i + 1];
            else
                leftDominoIdx[i] = 1e9;
        }
        string resStr;
        for (int i = 0; i < n; i++)
        {
            int leftDist = leftDominoIdx[i] - i;
            int rightDist = i - rightDominoIdx[i];
            if (leftDominoIdx[i] == 1e9 && rightDominoIdx[i] == -1e9)
            {
                resStr += ".";
                continue;
            }
            if (leftDist < rightDist)
                resStr += "L";
            else if (rightDist < leftDist)
                resStr += "R";
            else
                resStr += ".";
        }
        return resStr;
    }
};