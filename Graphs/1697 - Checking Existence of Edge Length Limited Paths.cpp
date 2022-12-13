// Problem Link: https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/description/

// Time Complexity: O(N * log N)
// Space Complexity: O(N)

class Solution
{
private:
    class DSU
    {
    public:
        vector<int> parent;
        vector<int> size;

        DSU(int n)
        {
            parent.resize(n + 1);
            size.resize(n + 1);
            for (int i = 1; i <= n; i++)
                parent[i] = (i), size[i] = 1;
        }

        int find(int n)
        {
            if (parent[n] == n)
                return n;
            return parent[n] = find(parent[n]);
        }

        void Union(int a, int b)
        {
            a = find(a);
            b = find(b);
            if (a != b)
            {
                if (size[a] < size[b])
                    swap(a, b);
                parent[b] = a;
                size[a] += size[b];
            }
        }

        int getPar(int i)
        {
            if (i != parent[i])
            {
                parent[i] = getPar(parent[i]);
            }
            return parent[i];
        }
    };

    static bool weightSort(const vector<int> &a, const vector<int> &b)
    {
        return a[2] < b[2];
    }

public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries)
    {
        DSU dsu(n);

        // Add query indices to help with organizing/ordering results.
        for (int i = 0; i < queries.size(); i++)
            queries[i].push_back(i);

        // Sort inputs
        sort(queries.begin(), queries.end(), [](auto &l, auto &r)
             { return l[2] < r[2]; });
        sort(edgeList.begin(), edgeList.end(), [](auto &l, auto &r)
             { return l.back() < r.back(); });

        int i = 0;
        vector<bool> result(queries.size());
        for (vector<int> &q : queries)
        {
            // Two pointer approach. Join the edges till their weight is less than the current query.
            while (i < edgeList.size() && edgeList[i][2] < q[2])
                dsu.Union(edgeList[i][0], edgeList[i++][1]);

            // If parents are same we know that their is a path.
            result[q.back()] = dsu.find(q[0]) == dsu.find(q[1]);
        }
        return result;
    }
};