//problem Link: https://leetcode.com/problems/verifying-an-alien-dictionary/description/

//time Complexity: O(n * m)
//space Complexity: O(26)

class Solution {
private:
    bool compareStrings(string &a, string &b, int nums[]){
        int n = a.size();
        int m = b.size();
        int i = 0;
        int j = 0;
        while( i < n && j < m ){
            if( a[i] != b[j] ) return (nums[a[i] - 'a'] < nums[b[j] - 'a']);
            i++, j++;
        }
        return i == n;
    }

public:
    bool isAlienSorted(vector<string>& words, string order) {
        int dict[26];
        for(int i = 0; i < 26; i++)
            dict[order[i] - 'a'] = i;
        int n = words.size();
        for(int i = 0; i < n - 1; i++){
            string &s = words[i];
            string &t = words[i + 1];
            if( !compareStrings(s, t, dict) ) return false;
        }
        return true;
    }
};
