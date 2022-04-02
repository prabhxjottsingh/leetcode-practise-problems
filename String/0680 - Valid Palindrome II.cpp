//Problem Link: https://leetcode.com/problems/valid-palindrome-ii/

//Time Complexity: O(N)
//Space Complexity: O(1)

class Solution {
private:
    bool check(int left, int right, string s){
        while(left < right){
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right){
            if(s[left] != s[right]){
                if( (!check(left + 1, right, s)) && (!check(left, right - 1, s)) )
                    return false;
                else
                    return true;
            }
            left++;
            right--;
        }
        return true;
    }
};