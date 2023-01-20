// Problem Link: https://practice.geeksforgeeks.org/problems/b64485d3994958cca8748991bb58668204b3e4c0/1

// time complexity: O(n)
// space complexity: O(n)

class Solution
{
public:
    int maxWeightCell(int N, vector<int> Edge)
    {
        int deg[N];
        memset(deg, 0, sizeof(deg));
        int i = 0;
        for (auto &a : Edge)
        {
            if (a == -1)
                continue;
            deg[a] += i;
            i++;
        }
        int maxDeg = 0;
        int resNode = 0;
        for (int i = 0; i < N; i++)
        {
            if (deg[i] > maxDeg)
            {
                maxDeg = deg[i];
                resNode = i;
            }
        }
        if (maxDeg == 0)
            return 0;
        return resNode;
    }
};