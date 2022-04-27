// Problem Link: https://leetcode.com/problems/smallest-string-with-swaps/

//Approach: Finding all conected indices and then assigning the characters in sorting order in all connected componenets

class Solution
{
private:
    void dfs(int i, string &s, vector<int> &pos, vector<char> &characters, vector<vector<int>> &graph, vector<bool> &isVis)
    {
        if (isVis[i] == 1)
            return;
        isVis[i] = 1;
        pos.push_back(i);
        characters.push_back(s[i]);
        for (auto &child : graph[i])
        {
            if (isVis[child] == 0)
                dfs(child, s, pos, characters, graph, isVis);
        }
    }

public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        int n = s.size();
        vector<vector<int>> graph(n);
        vector<bool> isVis(n, false);
        for (int i = 0; i < pairs.size(); i++)
        {
            int x = pairs[i][0], y = pairs[i][1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        string res(n, 'a');
        for (int i = 0; i < n; i++)
        {
            if (isVis[i] == 0)
            {
                vector<int> pos;
                vector<char> characters;
                dfs(i, s, pos, characters, graph, isVis);
                sort(pos.begin(), pos.end());
                sort(characters.begin(), characters.end());
                for (int j = 0; j < pos.size(); j++)
                {
                    res[pos[j]] = characters[j];
                }
            }
        }
        return res;
    }
};