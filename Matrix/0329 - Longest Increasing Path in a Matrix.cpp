//Problem Link: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

//Time Complexity: O(N * M)
//Space COmplexity: O(203 * 203)

class Solution {
private:
    int dp[203][203];
    
    vector<pair<int, int>> moves = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    
    bool isValid(int i, int j, int n, int m){
        
        if(i < 0 || i >= n)
            return false;
        
        if(j < 0 || j >= m)
            return false;
        
        return true;
    }
    
    int dfs(int i, int j, vector<vector<int>> &matrix){
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        if(!isValid(i, j, n, m))
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int maxLength = 0;
        
        for(auto &move : moves){
            int x = i + move.first;
            int y = j + move.second;
            
            if(isValid(x, y, n, m) && matrix[i][j] < matrix[x][y])
                maxLength = max(maxLength, dfs(x, y, matrix));
            
        }
        
        dp[i][j] = 1 + maxLength;
        
        return dp[i][j];
        
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxLen = 1;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(dp[i][j] == -1){
                    maxLen = max(maxLen, dfs(i, j, matrix));
                }
            }
        }
        return maxLen;
    }
};