// Problem Link: https://leetcode.com/problems/sort-the-students-by-their-kth-score/description/

// Time Complexity: O(n ^ 2)
// Space Compexity: O(1)

class Solution
{

public:
    vector<vector<int>> sortTheStudents(vector<vector<int>> &sc, int k)
    {
        int n = sc.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (sc[i][k] < sc[j][k])
                    swap(sc[i], sc[j]);
            }
        }
        return sc;
    }
};

// Time Complexity: O(n log N)
// Space Complexity: O(n)

class Solution
{

public:
    vector<vector<int>> sortTheStudents(vector<vector<int>> &sc, int k)
    {
        vector<pair<int, vector<int>>> pr;
        for (auto &a : sc)
            pr.push_back({a[k], a});
        sort(pr.rbegin(), pr.rend());
        vector<vector<int>> resVec;
        for (auto &a : pr)
            resVec.push_back(a.second);
        return resVec;
    }
};