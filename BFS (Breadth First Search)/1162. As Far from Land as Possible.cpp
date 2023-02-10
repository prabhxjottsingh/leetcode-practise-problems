//time complexity: O(n * m)
//space complexity: O(n * m)

class Solution {
private:
    vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    bool isSafe(int i, int j, int n, int m){
        if( i < 0 || i >= n ) return 0;
        if( j < 0 || j >= m ) return 0;
        return 1;
    }

public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if( grid[i][j] )
                    q.push({i, j});
            }
        }
        if( q.size() == 0 || q.size() == n * m ) return -1;
        int maxDist = -1;
        while( !q.empty() ){
            int sz = q.size();
            while( sz-- ){
                auto pr = q.front();
                q.pop();
                int x = pr.first;
                int y = pr.second;
                for(auto &a : moves){
                    int nx = x + a.first;
                    int ny = y + a.second;
                    if( isSafe(nx, ny, n, m) && !grid[nx][ny] ){
                        q.push({nx, ny});
                        grid[nx][ny] = 1;
                    }
                }
            }
            maxDist += 1;
        }
        return maxDist;
    }
};
