//tc: O(n)
//sc: O(1)

class Solution {
private:
    void revStr(string &s, int i, int j){
        if( i >= j ) return;
        swap(s[i], s[j]);
        revStr(s, i + 1, j - 1);
    }

    void makeStringsSizeEqual(string &a, string &b){
        int n = a.size();
        int m = b.size();
        if( m < n ) swap(a, b), swap(n, m);
        revStr(a, 0, n - 1);
        while( a.size() != m )
            a += "0";
        revStr(a, 0, m - 1);
    }

public:
    string addBinary(string a, string b) {
        int carry = 0;
        makeStringsSizeEqual(a, b);
        int n = a.size();
        int i = n - 1, j = n - 1;
        string rStr = "";
        for(; i > -1; i--, j--){
            bool allPos = ((a[i] - '0') && (b[j] - '0'));
            bool onePos = ((a[i] - '0') || (b[j] - '0'));
            if( allPos ){
                if( carry == 0 ) rStr += "0";
                else rStr += "1";
                carry = 1;
            }
            else if( onePos ){
                if( carry ) rStr += "0";
                else rStr += "1";
            }
            else{
                if( carry ) rStr += "1";
                else rStr += "0";
                carry = 0;
            }
        }
        if( carry ) rStr += "1";
        revStr(rStr, 0, rStr.size() - 1);
        return rStr;
    }
};
