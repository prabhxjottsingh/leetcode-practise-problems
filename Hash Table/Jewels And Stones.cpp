//Tags: Easy
//Problem Link: https://leetcode.com/problems/jewels-and-stones/
//Time Complexity: o(n)
//Space Complexity:/

class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        map<char, int> stonesThatAreJewels;
        int n = jewels.size();
        int m = stones.size();
        for (int i = 0; i < n; i++)
        {
            stonesThatAreJewels[jewels[i]]++;
        }
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            if (stonesThatAreJewels[stones[i]] > 0)
                count++;
        }
        return count;
    }
};