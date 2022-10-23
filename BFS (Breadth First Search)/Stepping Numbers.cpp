// Problem Link: https://practice.geeksforgeeks.org/problems/stepping-numberswrong-output1813/1

// Time Complexity: O(log(m))
// Space Complexity: O(M)

class Solution
{
public:
    int steppingNumbers(int n, int m)
    {
        queue<int> q;
        for (int i = 0; i <= 9; i++)
            q.push(i);
        int count = 0;
        while (!q.empty())
        {
            int val = q.front();
            q.pop();
            if (val >= n && val <= m)
            {
                count += 1;
            }
            if (val == 0 || val > m)
                continue;
            int newNum;
            int back = val % 10;
            if (back != 0)
            {
                newNum = val * 10 + ((back)-1);
                if (newNum <= m)
                    q.push(newNum);
            }
            if (back != 9)
            {
                newNum = val * 10 + ((back) + 1);
                if (newNum <= m)
                    q.push(newNum);
            }
        }
        return count;
    }
};