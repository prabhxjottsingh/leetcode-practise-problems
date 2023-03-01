//tc: O(Q * 30)
//sc: O(Q * 30)

class Solution{
    public:
        vector<int> updateQuery(int N,int Q,vector<vector<int>> &U)
        {
            vector<vector<int>> preVec(N + 1, vector<int> (30, 0));
            for(auto &a : U){
                a[0] -= 1;
                int &x = a[2];
                for(int i = 0; i < 30; i++){
                    if( (x & (1 << i)) )
                        preVec[a[0]][i] += 1, preVec[a[1]][i] -= 1;
                }
            }
            for(int i = 1; i <= N; i++){
                for(int j = 0; j < 30; j++){
                    preVec[i][j] += preVec[i - 1][j];
                }
            }
            vector<int> rVec(N);
            for(int i = 0; i < N; i++){
                int val = 0;
                for(int j = 0; j < 30; j++){
                    val |= ((preVec[i][j] > 0) << j);
                }
                rVec[i] = val;
            }
            return rVec;
        }
};
