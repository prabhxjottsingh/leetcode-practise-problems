//tc: O(n)
//sc: O(n)

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> hsh1, hsh2;
        for(auto &a : nums1)
            hsh1[a[0]] = a[1];
        for(auto &a : nums2)
            hsh1[a[0]] += a[1];
        vector<vector<int>> rVec;
        for(auto &a : hsh1)
            rVec.push_back({a.first, a.second});
        return rVec;
    }
};
