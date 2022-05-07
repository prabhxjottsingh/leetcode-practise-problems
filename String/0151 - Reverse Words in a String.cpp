//Problem Link: https://leetcode.com/problems/reverse-words-in-a-string/submissions/

//Time Complexity: O(N * M) -> M is the longest length of a single word
//Space Complexity: O(M)

class Solution {
private:
    void swapTheCharacter(char &a, char &b){
        char temp = a;
        a = b;
        b = temp;
    }
    
    void reverseThisSingleWord(string &s){
        int left = 0, right = (int)s.size() - 1;
        while(left < right){
            swapTheCharacter(s[left], s[right]);
            left++;
            right--;
        }
    }
    
public:
    string reverseWords(string s) {
        int n = s.size();
        string temp;
        string res;
        bool firstWord = true;
        for(int i = n-1; i > -1; i--){
            if(s[i] == ' ' && !temp.empty()){
                reverseThisSingleWord(temp);
                // cout << temp << " ";
                if(firstWord == true)
                    res += temp;
                else
                    res += " " + temp;
                firstWord = false;
                temp.clear();
            }
            else if(s[i] != ' '){
                temp += s[i];
            }
            // cout << s[i] << " ";
        }
        if(!temp.empty()){
            reverseThisSingleWord(temp);
            if(firstWord == true)
                res += temp;
            else
                res += " " + temp;
        }
        return res;    
    }
};