//Problem Link: https://leetcode.com/problems/word-subsets/
//Time Complexity: O(N * M)
//Space Complexity: O(1) -> Constant

class Solution {
private:
    bool checkSubset(int idxOne, int idxTwo, string a, string b){
        if( idxTwo < 0 )
            return true;
        if( idxOne < 0 )
            return false;
        if( a[idxOne] == b[idxTwo] )
            return checkSubset(idxOne - 1, idxTwo - 1, a, b);
        return checkSubset(idxOne - 1, idxTwo, a, b);
    }
    
    bool isSubset(string a, string b){
        bool flag = checkSubset(a.size() - 1, b.size() - 1, a, b);
        return flag;
    }
    
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        int n = words1.size();
        int m = words2.size();
        int oldSet[26];
        int countChars = 0;
        memset(oldSet, 0, sizeof(oldSet));
        for(int j = 0; j < m; j++){
            int newSet[26];
            memset(newSet, 0, sizeof(newSet));
            for(auto &a : words2[j]){
                newSet[a - 'a'] += 1;
                if( oldSet[a - 'a'] < newSet[a - 'a'] ){
                    oldSet[a - 'a'] += 1;
                    if( oldSet[a - 'a'] == 1 ){
                        countChars += 1;
                    }
                }
            }
        }
        // cout << countChars << endl;
        for(int i = 0; i < n; i++){
            int newSet[26];
            memset(newSet, 0, sizeof(newSet));
            int countSameChar = 0;
            for(auto &a : words1[i]){
                if( oldSet[a - 'a'] > newSet[a - 'a'] ){
                    newSet[a - 'a'] += 1;
                    if( oldSet[a - 'a'] == newSet[a - 'a'] )
                        countSameChar += 1;
                }
            }
            if( countChars == countSameChar )
                res.push_back(words1[i]);
            // cout << words1[i] << " -> " << countSameChar << endl;
            // compare(oldSet, newSet);
        }
        return res;
    }
};