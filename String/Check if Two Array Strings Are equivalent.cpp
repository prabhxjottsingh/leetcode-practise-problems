// Tags: String
// Difficulty: Easy
//Problem Link: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
//Time Complexity: O(n)
//Space Complexity: Constant


class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string string1, string2;
        for(int i=0; i<word1.size(); i++)
            string1+=(word1[i]);
        for(int i=0; i<word2.size(); i++)
            string2+=(word2[i]);
        if(string1!=string2)
            return false;
        return true;
    }
};