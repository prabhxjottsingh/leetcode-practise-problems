//Problem Link: https://leetcode.com/problems/maximum-product-of-word-lengths/

//Time Compleixty: O(N * N)
//Space Complexity: O(N)

class Solution {
    
public:
    int maxProduct(vector<string>& words) {
        int maxProd = 0;
        int n = words.size();
        vector<int> mask(n);
        for(int i = 0; i < n; i++){
            for(auto &ch : words[i])
                mask[i] |= (1 << (ch - 'a'));
            for(int j = 0; j < i; j++){
                if( (mask[i] & mask[j]) == 0){
                    int x = words[i].size();
                    int y = words[j].size();
                    maxProd = max(maxProd, x * y);
                }
            }
        }
        return maxProd;
    }
};