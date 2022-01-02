//Tag: Medium, Matrix
//Problem Link: https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/
//Time Complexity: O(n^2)

class Solution
{
public:
    vector<int> executeInstructions(int n, vector<int> &startPos, string s)
    {
        int m = s.size();
        int currX = startPos[0], currtY = startPos[1];
        vector<int> ans;
        for (int i = 0; i < m; i++)
        {
            int count = 0;
            currX = startPos[0];
            currY = startPos[1];
            for (int j = i; j < m; j++)
            {
                if (s[j] == 'L')
                {
                    currY = currY - 1;
                    if (currY >= 0)
                        count++;
                    else
                        break;
                }
                else if (s[j] == 'R')
                {
                    currY = currY + 1;
                    if (currY < n)
                        count++;
                    else
                        break;
                }
                else if (s[j] == 'D')
                {
                    currX = currX + 1;
                    if (currX < n)
                        count++;
                    else
                        break;
                }
                else if (s[j] == 'U')
                {
                    currX = currX - 1;
                    if (startX >= 0)
                        count++;
                    else
                        break;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};