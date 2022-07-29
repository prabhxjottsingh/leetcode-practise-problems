//Problem Link: https://leetcode.com/problems/find-and-replace-pattern/

//Time Complexity: O(N * M)
//Space Complexity: O(26)

class Solution {
private:
    bool followsPattern(string &a, string &b){
        vector<int> hash(26, -1);
        vector<bool> done(26, 0);
        int n = a.size();
        for(int i = 0; i < n; i++){
            int idx = b[i] - 'a';
            int newVal = a[i] - 'a';
            if( done[newVal] ){
                if( hash[idx] != newVal )
                    return false;
            }
            else{
                if( hash[idx] == -1 ){
                    done[newVal] = 1;
                    hash[idx] = newVal;
                }
                else
                    return false;
            }
        }
        return true;
    }
    
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        int n = words.size();
        for(int i = 0; i < n; i++){
            if( (int)words[i].size() == (int)pattern.size() && followsPattern(words[i], pattern) )
                res.push_back(words[i]);
        }
        return res;
    }
};