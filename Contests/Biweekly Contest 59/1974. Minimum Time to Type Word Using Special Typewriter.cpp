// Problem Link: https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/

// time Complextiy: O(N)
// space Compelxtyi :O(1)

class Solution
{
private:
    int movePrev(char maxi, char mini)
    {
        int cost = maxi - mini;
        return cost;
    }

    int moveForw(char maxi, char mini)
    {
        int costBack = mini - 'a' + 1;
        int costForw = 'z' - maxi;
        return costForw + costBack;
    }

public:
    int minTimeToType(string word)
    {
        int timeTaken = word.size();
        char prev = 'a';
        for (auto &a : word)
        {
            int costMovePrev = movePrev(max(a, prev), min(a, prev));
            int costMoveForw = moveForw(max(a, prev), min(a, prev));
            timeTaken += min(costMovePrev, costMoveForw);
            prev = a;
        }
        return timeTaken;
    }
};