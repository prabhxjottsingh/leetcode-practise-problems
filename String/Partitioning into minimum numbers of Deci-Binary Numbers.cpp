// Tags: String
// Difficulty: Easy
//Problem Link: https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
//Time Complexity: O(n)

//solution (that I thought)
//we just need to print the maximum number in the string, I came to this concluwion after running through a few test cases which were made by my own, expereince gained while doing CP helped :)

class Solution {
public:
    int minPartitions(string n) {
        int z = INT_MIN;
        for(int i=0; i<n.length(); i++){
            if(n[i]>z)
                z = n[i];
        }   
        return z-'0';
    }
};

