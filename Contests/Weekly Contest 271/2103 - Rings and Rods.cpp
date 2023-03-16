//tc: O(N * log N)
//sc: O(N)

class Solution {
public:
    int countPoints(string rings) {
        int count = 0;
        map<int, set<char>> freq;
        int n = rings.size();
        for(int i = 0; i < n; i += 2){
            freq[rings[i + 1] - '0'].insert(rings[i]);
        }
        for(auto &a : freq){
            if( a.second.size() == 3 )
                count += 1;
        }
        return count;
    }
};
