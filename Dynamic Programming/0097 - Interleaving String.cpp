class Solution {
private:
    int dp[101][101];
    bool func(int idxOne, int idxTwo, int idxThree, string &s1, string s2, string s3) {
        bool flag = false;
        if ( idxThree == -1 ) {

            if ( idxOne == -1 && idxTwo == -1 )
                return true;
            return false;

        }

        if ( idxOne > -1 && idxTwo > -1 && dp[idxOne][idxTwo] != -1 )
            return dp[idxOne][idxTwo];

        if ( idxOne > -1  && idxTwo > -1 && s1[idxOne] == s3[idxThree] && s2[idxTwo] == s3[idxThree] ) {
            flag |= func( idxOne - 1, idxTwo, idxThree - 1, s1, s2, s3 );
            flag |= func( idxOne, idxTwo - 1, idxThree - 1, s1, s2, s3 );
        }
        else if ( idxOne > -1  &&  s1[idxOne] == s3[idxThree] ) {
            flag |= func( idxOne - 1, idxTwo, idxThree - 1, s1, s2, s3 );
        }
        else if ( idxTwo > -1 && s2[idxTwo] == s3[idxThree] ) {
            flag |= func( idxOne, idxTwo - 1, idxThree - 1, s1, s2, s3 );
        }

        if ( idxOne > -1 && idxTwo > -1 )
            dp[idxOne][idxTwo] = flag;

        return flag;

    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp, -1, sizeof(dp));
        bool flag = func(s1.size() - 1, s2.size() - 1, s3.size() - 1, s1, s2, s3);
        return flag;
    }
};