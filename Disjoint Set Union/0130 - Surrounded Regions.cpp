//Problem Link: https://leetcode.com/problems/surrounded-regions/description/

//Time Complexity: O(N * M * log (N * M))
//Space Complexity: O(M * N)

class Solution {
private:
    vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    bool isValid(int i, int j, int n, int m){
        if( i < 0 | i >= n || j < 0 || j >= m ) return 0;
        return 1;
    }

    class DSUst{
    private:
        vector<int> par;

    public:

        DSUst(int n){
            par.resize(n);
            for(int i = 0; i < n; i++)
                par[i] = i;
        }

        int findPar(int n){
            if( n == par[n] ) return n;
            return par[n] = findPar(par[n]);
        }

        void merge(int a, int b){
            a = findPar(a);
            b = findPar(b);
            if( a == b )
                return;
            par[b] = a;
        }

    };

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        DSUst unionSt(n * m);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if( board[i][j] == 'O' ){
                    for(auto &a : moves){
                        int ni = a.first + i;
                        int nj = a.second + j;
                        if( isValid(ni, nj, n, m) && board[ni][nj] == 'O' ){
                            int a = i * m + j;
                            int b = ni * m + nj;
                            if( unionSt.findPar(a) != unionSt.findPar(b) )
                                unionSt.merge(a, b);
                        }
                    }
                }
            }
        }
        set<int> dontChange;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if( (i == 0 || i == n - 1 || j == 0 || j == m - 1) && board[i][j] == 'O' ){
                    int a = i * m + j;
                    dontChange.insert(unionSt.findPar(a));
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if( board[i][j] == 'O' ){
                    int a = i * m + j;
                    if( !dontChange.count(unionSt.findPar(a)) )
                        board[i][j] = 'X';
                }
            }
        }
    }
};
