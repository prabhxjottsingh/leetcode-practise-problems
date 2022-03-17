// Problem Link: https://leetcode.com/problems/score-of-parentheses/
// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        int stringSize = s.size();
        stack<int> calcStack;
        for (int i = 0; i < stringSize; i++)
        {
            if (s[i] == '(')
            {
                calcStack.push(-1);
            }
            else
            {
                if (calcStack.top() == -1)
                {
                    calcStack.pop();
                    calcStack.push(1);
                }
                else
                {
                    int innerSum = 0;
                    while (calcStack.top() != -1)
                    {
                        innerSum += calcStack.top();
                        calcStack.pop();
                    }
                    calcStack.pop();
                    calcStack.push(2 * innerSum);
                }
            }
        }
        int score = 0;
        while (!calcStack.empty())
        {
            score += calcStack.top();
            calcStack.pop();
        }
        return score;
    }
};