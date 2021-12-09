//Tag: Medium
//Problem Link: https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/
//Time Complexity: O(n)
//Space Complexity: constant

class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        int n = colors.size(), alice = 0, bob = 0;
        for (int i = 0; i < n; i++)
        {
            if (colors[i] == 'A' && colors[i + 1] == 'A' && colors[i + 2] == 'A' && i + 2 < n)
                alice++;
            if (colors[i] == 'B' && colors[i + 1] == 'B' && colors[i + 2] == 'B' && i + 2 < n)
                bob++;
        }
        if (bob < alice)
            return true;
        return false;
    }
};