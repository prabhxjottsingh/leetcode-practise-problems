//Tags: Greedy, Maths
//Problem Link: https://leetcode.com/problems/minimum-moves-to-reach-target-score/
//Space Complexity: O(1) -> Constant

class Solution
{
public:
    int minMoves(int target, int maxDoubles)
    {
        int count = 0, init = 1;
        while ((target > 1) && (maxDoubles))
        {
            if (target % 2 == 0)
                target /= 2;
            else
            {
                count++;
                target /= 2;
            }
            maxDoubles--;
            count++;
        }
        count += (target - 1);
        return count;
    }
};