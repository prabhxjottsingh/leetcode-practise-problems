// Problem Link: https://leetcode.com/problems/keys-and-rooms/

// Time Complexity: O(N * M)
// Space Complexity: O(N * M)

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        vector<int> isVis(n, 0);
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int currRoom = q.front();
            q.pop();
            if (isVis[currRoom])
                continue;
            isVis[currRoom] = 1;
            for (auto &key : rooms[currRoom])
            {
                if (!isVis[key])
                    q.push(key);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (!isVis[i])
                return false;
        }
        return true;
    }
};