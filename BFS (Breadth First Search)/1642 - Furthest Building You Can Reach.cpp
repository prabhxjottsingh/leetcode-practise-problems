//tc: O(n * log N * n)
//sc: O(N)

class Solution {
private:
    bool isPosTill(int idx, vector<int> hts, int br, int lads){
        vector<int> diffArr;
        for(int i = 0; i < idx; i++){
            if( hts[i + 1] > hts[i] )
                diffArr.push_back(hts[i + 1] - hts[i]);
        }
        int n = diffArr.size();
        sort(diffArr.begin(), diffArr.end(), greater<int>());
        for(int i = lads; i < n; i++){
            br -= diffArr[i];
        }
        return br >= 0;
    }

public:
    int furthestBuilding(vector<int>& hts, int br, int lads) {
        int n = hts.size();
        int low = 0;
        int high = n - 1;
        int lastIdx = 0;
        while( low <= high ){
            int mid = (low + high) / 2;
            if( isPosTill(mid, hts, br, lads) )
                low = mid + 1, lastIdx = mid;
            else
                high = mid - 1;
        }
        return lastIdx;
    }
};
