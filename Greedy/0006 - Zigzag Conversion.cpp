//Tc: O(n)
//sc: O(n * numRows)

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        vector<vector<char>> arr(numRows, vector<char> (n, '#'));
        int idx = 0;
        bool firstPat = 1;
        int j = 0;
        while( idx < n ){
            for(int i = 0; i < numRows && idx < n ; i++){
                arr[i][j] = s[idx];
                idx++;
            }
            j++;
            int i = numRows - 2;
            while( i > 0 && idx < n ){
                arr[i][j] = s[idx];
                idx++;
                i--;
                j++;
            }
        }
        string res;
        for(auto &a : arr){
            for(auto &b : a){
                if( b != '#' )
                    res.push_back(b);
            }
        }
        return res;
    }
};
