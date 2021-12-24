//Tag: Easy
//Topic: String
//Problem Link: https://leetcode.com/problems/consecutive-characters/
//Time Complexity: O(n)

class Solution
{
public:
    int maxPower(string s)
    {
        int count = 0, maxCount = 0;
        char lastEle = s[0];
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == lastEle)
                count++;
            else
                count = 1;
            maxCount = max(count, maxCount);
            lastEle = s[i];
        }
        return maxCount;
    }
};