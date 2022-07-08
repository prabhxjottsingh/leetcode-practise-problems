class Solution {
private:
    vector<pair<int, int>> moves = { {0, 1}, {1, 0}, { -1, 0}, {0, -1} };

    bool isPossible(int i, int j, int N, int M) {

        if ( i < 0 || i >= N )
            return false;
        if ( j < 0 || j >= M )
            return false;
        return true;

    }

public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if (A[0][0] == 0)
            return -1;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});
        int level[N][M] = {};
        while ( !q.empty() ) {
            auto front = q.front();
            q.pop();
            int x = front.first;
            int y = front.second.first;
            int dist = front.second.second;
            for (auto &move : moves) {
                int newX = x + move.first;
                int newY = y + move.second;
                if ( isPossible(newX, newY, N, M) && A[newX][newY] == 1 ) {
                    q.push({newX, {newY, dist + 1}});
                    A[newX][newY] = 0;
                }
            }
            level[x][y] = dist;
            if ( x == X && y == Y )
                break;
        }
        return level[X][Y] != 0 ? level[X][Y] : -1 ;
    }
};