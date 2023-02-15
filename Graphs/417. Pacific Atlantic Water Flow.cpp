//tc: O(n * m)
//sc: O(n * m)

class Solution {
private:
    bool isValid(int i, int j, int n, int m){
        if( i < 0 || i >= n ) return false;
        if( j < 0 || j >= m ) return false;
        return true;
    }

    vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    void dfs(int i, int j, vector<vector<int>> &isVis, vector<vector<int>> &mat){
        isVis[i][j] = 1;
        for(auto &a : moves){
            int ni = a.first + i;
            int nj = a.second + j;
            if( !isValid(ni, nj, mat.size(), mat[0].size()) ) continue;
            if( isVis[ni][nj] ) continue;
            if( mat[ni][nj] < mat[i][j] ) continue;
            // cout << i << " " << j << " -> " << ni << " " << nj << endl;
            dfs(ni, nj, isVis, mat);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ind(n, vector<int> (m, 0));
        vector<vector<int>> arab(n, vector<int> (m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if( i == 0 || j == 0 )
                    dfs(i, j, ind, mat);
                if( i == n - 1 || j == m - 1 )
                    dfs(i, j, arab, mat);
            }
        }
        vector<vector<int>> rVec;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                if( ind[i][j] == arab[i][j] && ind[i][j] == 1 ) rVec.push_back({i, j});
        }
        return rVec;
    }
};
