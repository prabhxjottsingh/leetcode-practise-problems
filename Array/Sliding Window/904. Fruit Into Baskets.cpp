//tc: O(N * log N)
//sc: O(N)

//Problem link: https://leetcode.com/problems/fruit-into-baskets/description/

//if we look closely in this problem, we just have to find the longest window of 2 distinct elements jsut nothing else

class Solution {
public:
    int totalFruit(vector<int>& fr) {
        int n = fr.size();
        int i = 0;
        int j = 0;
        unordered_map<int, int> freq;
        int len = 0;
        while( i < n ){
            while( j < n && freq.size() <= 2 ){
                freq[fr[j]]++;
                j++;
            }
            if( j == n && freq.size() <= 2 )
                len = max(len, j - i);
            else
                len = max(len, j - i - 1);

            freq[fr[i]]--;
            if( freq[fr[i]] == 0 )
                freq.erase(fr[i]);
            i++;
        }
        return len;
    }
};
