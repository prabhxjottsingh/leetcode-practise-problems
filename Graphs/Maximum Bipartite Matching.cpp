//Time Complexity: O(N * N * N)
//sc: O(N)

class Solution {
private:
    bool dfs(int src, vector<vector<int>> &G, vector<int> &isVis, vector<int> &job){
        int m = G[0].size();
        for(int i = 0; i < m; i++){
            if( G[src][i] == 1 && !isVis[i] ){
                isVis[i] = 1;
                if( job[i] == -1 || dfs(job[i], G, isVis, job) ){
                    job[i] = src;
                    return true;
                }
            }
        }
        return false;
    }

public:
    int maximumMatch(vector<vector<int>>&G){
        int n = G.size();
        int m = G[0].size();
        int count = 0;
        vector<int> job(m, -1);
        for(int i = 0; i < n; i++){
            vector<int> isVis(m, 0);
            if( dfs(i, G, isVis, job) ){
                count += 1;
            }
        }
        return count;
    }


};
