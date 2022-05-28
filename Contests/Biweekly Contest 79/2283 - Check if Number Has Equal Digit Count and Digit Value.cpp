//Problem Link: https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value/

//Time Complexity: O(N)
//Space Complexity: O(10)

class Solution {
public:
    bool digitCount(string num) {
        map<int, int> mp;
        for(auto &a:num){
            mp[a - '0']++;
        }
        for(int i = 0; i < (int)num.size(); i++){
            if(mp[i] != (num[i] - '0'))
                return false;
        }
        return true;
    }
};