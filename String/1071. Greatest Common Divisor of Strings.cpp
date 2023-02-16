//tc: O(n)
//sc: O(n * n)

class Solution {
private:
    bool isPosLen(string &s, string &t, int len){
        int n = s.size();
        int m = t.size();
        if( m > n ) swap(n, m);
        int i = 0;
        while( i < m ){
            if( t[i] != t[i % len] ) return 0;
            i++;
        }
        i = 0;
        while( i < n ){
            if( s[i] != t[i % len] ) return 0;
            i++;
        }
        return 1;
    }

public:
    string gcdOfStrings(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        if( m > n ) swap(n, m), swap(str1, str2);
        int maxLen = 0;
        for(int i = n; i > 0; i--){
            if( n % i == 0 && m % i == 0 ){
                if( isPosLen(str1, str2, i) ){
                    maxLen = i;
                    break;
                }
            }
        }
        string rStr = "";
        for(int i = 0; i < maxLen; i++)
            rStr += str1[i];
        return rStr;
    }
};
