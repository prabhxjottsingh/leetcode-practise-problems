//Problem Link: https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/description/

//Time Complexity: O(N)
//Space Complexity: O(26)

class Solution {
private:
    void dfs(int node, int par, vector<int> graph[], string &labels, vector<int> &resVec, vector<int> &freq){
        int prevCount = freq[labels[node] - 'a'];
        freq[labels[node] - 'a'] += 1;
        for(auto &a : graph[node]){
            if( a == par )  continue;
            dfs(a, node, graph, labels, resVec, freq);
        }
        resVec[node] += freq[labels[node] - 'a'] - prevCount;
    }

public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> graph[n];
        for(auto &a : edges)
            graph[a[0]].push_back(a[1]), graph[a[1]].push_back(a[0]);
        vector<int> resVec(n, 0);
        vector<int> freq(26, 0);
        dfs(0, -1, graph, labels, resVec, freq);
        return resVec;
    }
};
