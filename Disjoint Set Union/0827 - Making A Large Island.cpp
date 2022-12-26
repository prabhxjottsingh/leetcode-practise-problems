// Problem Link: https://leetcode.com/problems/making-a-large-island/description/

// Time Complexity: O(N * N)
// Space Complexity: O(N * N)

class DSU
{
private:
    vector<int> par;
    vector<int> size;

public:
    DSU(int n)
    {
        par.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++)
            par[i] = i, size[i] = 1;
    }

    int findPar(int n)
    {
        if (par[n] == n)
            return n;
        return par[n] = findPar(par[n]);
    }

    void Union(int a, int b)
    {
        a = findPar(a);
        b = findPar(b);
        if (a == b)
            return;
        if (size[a] < size[b])
            par[a] = b, size[b] += size[a];
        else
            swap(a, b), par[a] = b, size[b] += size[a];
    }

    int returnSize(int n)
    {
        return size[n];
    }
};

class Solution
{
private:
    bool isValid(int i, int j, int n)
    {
        if (i < 0 || i >= n)
            return false;
        if (j < 0 || j >= n)
            return false;
        return true;
    }

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        DSU st(n * n);
        int dr[] = {0, -1, 1, 0};
        int dc[] = {1, 0, 0, -1};
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (grid[i][j] == 1)
                {
                    // cout << i << ", " << j << " -> ";
                    for (int ind = 0; ind < 4; ind++)
                    {
                        int newR = dr[ind] + i;
                        int newC = dc[ind] + j;

                        if (isValid(newR, newC, n) && grid[newR][newC] == 1)
                        {
                            int node = i * n + j;
                            int newNode = newR * n + newC;
                            // cout << newR << ", " << newR << " || ";
                            if (st.findPar(node) != st.findPar(newNode))
                                st.Union(node, newNode);
                        }
                    }
                    // cout << endl;
                }
            }
        }

        int maxSize = 0;

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    found = true;
                    set<int> sT;
                    // cout << i << ", " << j << " -> ";
                    for (int ind = 0; ind < 4; ind++)
                    {
                        int newR = dr[ind] + i;
                        int newC = dc[ind] + j;

                        if (isValid(newR, newC, n) && grid[newR][newC] == 1)
                        {
                            // cout << newR << ", " << newR << " || ";
                            sT.insert(st.findPar(newR * n + newC));
                        }
                    }
                    int totSize = 0;
                    for (auto &a : sT)
                    {
                        totSize += st.returnSize(a);
                        // cout << a << " ";
                    }

                    maxSize = max(maxSize, totSize + 1);
                    // cout << endl;
                }
            }
        }

        if (!found)
            return n * n;

        return maxSize;
    }
};