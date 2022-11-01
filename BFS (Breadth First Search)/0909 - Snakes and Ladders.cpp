// Problem Link: https://leetcode.com/problems/snakes-and-ladders/

// Time Complexity: O(N * N)
// Space Complexity: O(N + N)

class Solution
{
private:
    int func(int n, map<int, int> &ladders)
    {
        vector<bool> isVis((n * n) + 1, 0);
        int countSteps = 0;
        queue<pair<int, int>> q;
        q.push({1, countSteps});
        while (!q.empty())
        {
            auto front = q.front();
            int val = front.first;
            int steps = front.second;
            if (val == n * n)
                return steps;
            q.pop();
            if (isVis[val])
                continue;
            isVis[val] = 1;
            for (int i = 1; i <= 6; i++)
            {
                int newVal = val + i;
                if (newVal > n * n)
                    continue;
                if (ladders.count(newVal))
                    newVal = ladders[newVal];
                q.push({newVal, steps + 1});
            }
        }
        return -1;
    }

public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        map<int, int> snakes, ladders;
        int n = board.size();
        int lastVal = n * n;
        int count = 0;
        for (int i = n - 1; i >= 0; i--, count++)
        {
            if (count & 1)
                reverse(board[i].begin(), board[i].end());
            for (int j = 0; j < n; j++)
            {
                int tempI = n - i - 1;
                int currVal = (tempI)*n + (j + 1);
                if (board[i][j] != -1)
                {
                    ladders[currVal] = board[i][j];
                }
            }
        }
        int minSteps = func(n, ladders);
        return minSteps;
    }
};