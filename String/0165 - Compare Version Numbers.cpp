//Problem Link: https://leetcode.com/problems/compare-version-numbers/

//Time Complexity: O(n+m)
//Space Complexity: O(1)

class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        int n = version1.size(), m = version2.size();
        int i = 0, j = 0;
        
        while( ((i < n) || (j < m)) ){
            int number1 = 0;
            int number2 = 0;
        
            while( (i < n) && (version1[i] != '.') ){
                number1 = (number1 * 10) + (version1[i] - '0');
                i++;
            }
            
            while( (j < m) && (version2[j] != '.') ){
                number2 = (number2 * 10) + (version2[j] - '0');
                j++;
            }
            
            if(number1 > number2)
                return 1;
            else if(number2 > number1)
                return -1;
            
            i++;
            j++;
            
        }
        return 0;
    }
};