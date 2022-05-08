// Problem Link: https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    vector<pair<int, int>> movements = {
        {1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

    static bool isValid(int x, int y, int N)
    {
        if (x <= 0 || x > N)
            return false;
        else if (y <= 0 || y > N)
            return false;
        return true;
    }

    int bfs(vector<int> KnightPos, vector<int> TargetPos, int N)
    {
        int level[N + 1][N + 1] = {0};
        bool isVis[N + 1][N + 1] = {false};
        int sourceX = KnightPos[0];
        int sourceY = KnightPos[1];
        int distX = TargetPos[0];
        int distY = TargetPos[1];
        queue<pair<int, int>> q;
        q.push({sourceX, sourceY});
        isVis[sourceX][sourceY] = 1;
        while (!q.empty())
        {
            pair<int, int> v = q.front();
            q.pop();
            int x = v.first;
            int y = v.second;
            for (auto &move : movements)
            {
                int pointX = move.first + x;
                int pointY = move.second + y;
                if (isValid(pointX, pointY, N) == false || isVis[pointX][pointY] == 1)
                    continue;
                q.push({pointX, pointY});
                level[pointX][pointY] = level[x][y] + 1;
                isVis[pointX][pointY] = 1;
            }
        }
        return level[distX][distY];
    }

public:
    // Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        int res = bfs(KnightPos, TargetPos, N);
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        vector<int> KnightPos(2);
        vector<int> TargetPos(2);
        int N;
        cin >> N;
        cin >> KnightPos[0] >> KnightPos[1];
        cin >> TargetPos[0] >> TargetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends