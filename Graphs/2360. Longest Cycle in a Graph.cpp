//tc: O(n)
//sc: O(n)

static const int N = 1e5 + 7;
vector<int> graph[N];
vector<int> hsh;
vector<int> isVisFinal;

class Solution {
private:
    int maxLen = 0;

    void dfs(int node, vector<bool> &isVis, int idx){
        if( isVisFinal[node] ){
            if( isVis[node] != 1 ) return;
            maxLen = max(idx - hsh[node], maxLen);
            return;
        }
        isVisFinal[node] = 1;
        isVis[node] = 1;
        hsh[node] = idx;
        for(auto &child : graph[node]){
            dfs(child, isVis, idx + 1);
        }
        isVis[node] = 0;
    }

public:
    int longestCycle(vector<int>& edges){
        int n = edges.size();
        for(int i = 0; i < n; i++){
            if( edges[i] == -1 ) continue;
            graph[i].push_back(edges[i]);
        }
        isVisFinal.resize(n);
        for(int i = 0; i < n; i++)
            isVisFinal[i] = 0;
        hsh.resize(n, 0);
        vector<bool> isVis(n, 0);
        for(int i = 0; i < n; i++){
            if( !isVisFinal[i] ){
                dfs(i, isVis, 0);
            }
            graph[i].clear();
            isVis.clear();
        }
        if( maxLen == 0 ) return -1;
        return maxLen;
    }
};
