// Problem Link: https://leetcode.com/problems/course-schedule/

// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &pre)
    {
        vector<int> graph[numCourses + 1];
        int n = pre.size();
        vector<int> deg(numCourses, 0);
        for (int i = 0; i < n; i++)
        {
            graph[pre[i][0]].push_back(pre[i][1]);
            graph[pre[i][1]].push_back(pre[i][0]);
            deg[pre[i][1]] += 1;
        }
        int count = 0;
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (deg[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count += 1;
            for (auto &it : graph[node])
            {
                deg[it] -= 1;
                if (deg[it] == 0)
                    q.push(it);
            }
        }
        return count == numCourses;
    }
};