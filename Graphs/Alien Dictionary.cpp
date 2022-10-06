class Solution
{
public:
    string findOrder(string dict[], int N, int K)
    {
        int n = N;
        vector<int> graph[26];
        vector<int> deg(K, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int sz = min(dict[i].size(), dict[j].size());
                for (int k = 0; k < sz; k++)
                {
                    int u = dict[i][k] - 'a';
                    int v = dict[j][k] - 'a';
                    if (u != v)
                    {
                        graph[u].push_back(v);
                        deg[v] += 1;
                        break;
                    }
                }
                break;
            }
        }
        string res;
        queue<int> q;
        for (int i = 0; i < 26; i++)
        {
            if (!deg[i])
                q.push(i);
        }
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            res += node + 'a';
            for (auto &a : graph[node])
            {
                deg[a] -= 1;
                if (!deg[a])
                    q.push(a);
            }
        }
        // cout << res;
        return res;
    }
};