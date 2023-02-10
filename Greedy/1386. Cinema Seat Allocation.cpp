//time complexity: O(n * log n)
//space complexity: O(n)

class Solution {
private:
    vector<vector<int>> pr = {{4, 5, 6, 7}, {2, 3, 4, 5}, {6, 7, 8, 9}};

    bool isPos(set<int> &nums){
        bool isVis[11];
        memset(isVis, 0, sizeof(isVis));
        for(auto &a : nums)
            isVis[a] = 1;
        bool flag = 0;
        for(auto &a : pr){
            bool tFlag = 1;
            for(auto &b : a)
                tFlag &= !isVis[b];
            flag |= tFlag;
        }
        return flag;
    }

public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& resSt) {
        int m = resSt.size();
        unordered_map<int, set<int>> freq;
        for(auto &a : resSt){
            freq[a[0]].insert(a[1]);
        }
        int count = 0;
        count += 2 * (n - freq.size());
        for(auto &b : freq){
            set<int> &a = b.second;
            if( a.size() == 2 && *a.begin() == 1 && *(--a.end()) == 10 )
                count += 2;
            else if( a.size() == 1 ){
                if( *a.begin() == 1 || *a.begin() == 10 )
                    count += 2;
                else
                    count += 1;
            }
            else
                count += isPos(b.second);
        }
        return count;
    }
};
