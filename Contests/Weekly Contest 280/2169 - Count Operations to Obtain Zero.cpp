// Problem Link: https://leetcode.com/contest/weekly-contest-280/problems/count-operations-to-obtain-zero/

class Solution
{
public:
    int countOperations(int num1, int num2)
    {
        int count = 0;
        while ((num1 != 0) && (num2 != 0))
        {
            if (num1 > num2)
                num1 -= num2;
            else
                num2 -= num1;
            count++;
        }
        return count;
    }
};