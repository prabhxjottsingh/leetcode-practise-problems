//tc: O(n * m * k)
//sc: O(n * mclass Solution {
class Solution {
private:
    vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {-1, 1}, {1, -1}, {1, 1}, {-1, -1}};
    map<pair<int, int>, int> dir;

    bool isSafe(int i, int j, int n, int m){
        if( i < 0 || i >= n ) return 0;
        if( j < 0 || j >= m ) return 0;
        return 1;
    }

    bool dfs(int i, int j, int idx, string &word, vector<vector<char>> &grid, vector<vector<bool>> &isVis, int prevDir){
        isVis[i][j] = 1;
        if( idx == word.size() ) return true;
        bool flag = false;
        for(auto &move : moves){
            int ni = i + move.first;
            int nj = j + move.second;
            if( !isSafe(ni, nj, grid.size(), grid[0].size()) || isVis[ni][nj] ) continue;
            if( grid[ni][nj] == word[idx] && (prevDir == -1 || dir[{move.first, move.second}] == prevDir) )
                flag |= dfs(ni, nj, idx + 1, word, grid, isVis, dir[{move.first, move.second}]);
        }
        isVis[i][j] = 0;
        return flag;
    }

public:
    vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
        int idx = 1;
        for(auto &a : moves){
            dir[{a.first, a.second}] = idx;
            idx += 1;
        }
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> resVec;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if( grid[i][j] == word[0] ){
                    vector<vector<bool>> isVis(n, vector<bool> (m, 0));
                    if( dfs(i, j, 1, word, grid, isVis, -1) ){
                        resVec.push_back({i, j});
                    }
                }
            }
        }
        return resVec;
    }
};
