//sc: O(1)
//tc: O(N * m)

class Solution{
private:
    map<char, pair<int, int>> dir = {{'R', {0, 1}}, {'D', {1, 0}}, {'U', {-1, 0}}, {'L', {0, -1}}};
    map<char, char> newDir = {{'U', 'R'}, {'R', 'D'}, {'D', 'L'}, {'L', 'U'}};

    bool isExit(int i, int j, int R, int C){
        if( i >= R || i < 0 || j >= C || j < 0 ) return 1;
        return 0;
    }

    pair<int, int> func(int i, int j, int R, int C, char currDir, vector<vector<int>> &matrix){
        if( matrix[i][j] == 1 )
            currDir = newDir[currDir], matrix[i][j] = 0;
        int nx = i + dir[currDir].first;
        int ny = j + dir[currDir].second;
        if( isExit(nx, ny, R, C) ) return {i, j};
        return func(nx, ny, R, C, currDir, matrix);
    }

public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int R, int C){
        pair<int, int> exitCords = func(0, 0, R, C, 'R', matrix);
        return exitCords;
    }
};
