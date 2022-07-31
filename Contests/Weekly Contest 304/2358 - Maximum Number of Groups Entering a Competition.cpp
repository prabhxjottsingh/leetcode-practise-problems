//Problem Link: https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition/
//Time Complexity: O(N)
//Space Complexity: O(1)

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        sort(grades.begin(), grades.end());
        int countGroups   = 0;
        int countPrevNums = 0;
        int countPrevSum = 0;
        int presentCount = 0;
        int presentSum = 0;
        for(int i = 0; i < n; i++){
            presentCount += 1;
            presentSum += grades[i];
            if( presentSum > countPrevSum && presentCount > countPrevNums ){
                countGroups += 1;
                countPrevSum = presentSum;
                presentSum = 0;
                countPrevNums = presentCount;
                presentCount = 0;
            }
        }
        return countGroups;
    }
};