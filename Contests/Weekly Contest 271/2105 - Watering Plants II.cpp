//tc: O(N)
//sc: O(1)

class Solution {
public:
    int minimumRefill(vector<int>& pl, int capA, int capB) {
        int count = 0;
        int i = 0;
        int initA = capA;
        int initB = capB;
        int j = pl.size() - 1;
        while( i < j ){
            if( capA >= pl[i] )
                capA -= pl[i];
            else
                capA = initA - pl[i], count += 1;
            if( capB >= pl[j] )
                capB -= pl[j];
            else
                capB = initB - pl[j], count += 1;
            ++i, --j;
        }
        if( i == j ){
            if( capA < pl[i] && capB < pl[i] ) count += 1;
        }
        return count;
    }
};
