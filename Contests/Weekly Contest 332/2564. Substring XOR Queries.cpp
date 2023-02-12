//tc: O(n * 30 + q * log N)
//sc: O(n)

class Solution {
private:

    long strToDec(string &s){
        long long val = 0;
        int n = s.size();
        int idx = 0;
        for(int i = n - 1; i > -1; i--){
            if( s[i] == '1' )
                val |= (1ll << idx);
            idx++;
        }
        return val;
    }
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> rVec;
        map<long, pair<int, int>> storeIdx;
        int n = s.size();
        for(int i = 0; i < n; i++){
            string tStr = "";
            if( s[i] == '0' ) {
                if( !storeIdx.count(0) )
                    storeIdx[0] = {i, i};
                continue;
            }
            for(int j = i; j < min(n, i + 31); j++){
                tStr += s[j];
                long long val = strToDec(tStr);
                if( storeIdx.count(val) ) continue;
                storeIdx[val] = {i, j};
            }
        }
        for(auto &a : queries){
            long long _xor = (a[0] ^ a[1]);
            if( !storeIdx.count(_xor) )
                rVec.push_back({-1, -1});
            else
                rVec.push_back({storeIdx[_xor].first, storeIdx[_xor].second});
        }
        return rVec;
    }
};
