//Problem Link: https://leetcode.com/problems/number-of-islands/

//Time Complexity: O(N+M)
//Space Complexity: O(1)

class Solution {

private:
    void dfs(int i, int j, vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        
        if(i < 0 || j < 0 || i >= n || j >= m)
            return;
        
        if(grid[i][j] == '0' || isVis.count({i,j}))
            return;
        
        grid[i][j] = '0';
        
        dfs(i + 1, j, grid);
        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i, j - 1, grid);
        
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int countIslands = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    dfs(i, j, grid);
                    countIslands++;
                }

            }
        }
        return countIslands;
    }
};