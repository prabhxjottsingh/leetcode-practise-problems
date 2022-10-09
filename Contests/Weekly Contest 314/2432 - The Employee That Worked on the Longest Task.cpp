// Problem Link: https://leetcode.com/problems/the-employee-that-worked-on-the-longest-task/

// Time Complexity: O(N)
// space ComplexitY: O(n)

class Solution
{
public:
    int hardestWorker(int n, vector<vector<int>> &logs)
    {
        map<int, long> timeEmp;
        int prev = 0;
        int i = 0;
        for (auto &a : logs)
        {
            timeEmp[i] += abs(prev - a[1]);
            prev = a[1];
            i += 1;
        }
        long longestTime = 0;
        int empId = 0;
        for (auto &a : timeEmp)
        {
            if (longestTime < a.second)
            {
                longestTime = a.second;
                empId = logs[a.first][0];
            }
            else if (longestTime == a.second)
            {
                empId = min(logs[a.first][0], empId);
            }
        }
        return empId;
    }
};