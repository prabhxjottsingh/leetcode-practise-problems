// Tags: String
// Difficulty: Easy
//Problem Link: https://leetcode.com/problems/final-value-of-variable-after-performing-operations/
//Time Complexity: O(n)

///solution (that I thought)
class Solution
{
public:
    int finalValueAfterOperations(vector<string> &operation)
    {
        int x = 0;
        int n = operation.size();
        for (int i = 0; i < n; i++)
        {
            if ((operation[i][0] == '+') || (operation[i][2] == '+'))
                x++;
            else
                x--;
        }
        return x;
    }
};

//Another Solution (faster)
class Solution
{
public:
    int finalValueAfterOperations(vector<string> &operation)
    {
        int x = 0;
        int n = operation.size();
        for (int i = 0; i < n; i++)
        {
            if ((operation[i][1] == '+'))
                x++;
            else
                x--;
        }
        return x;
    }
};