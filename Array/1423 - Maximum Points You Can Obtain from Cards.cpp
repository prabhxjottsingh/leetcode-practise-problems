class Solution
{

public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int sum = 0, tempSum = 0;
        for (int i = 0; i < n; i++)
            sum += cardPoints[i];
        int removedSize = n - k;
        for (int i = 0; i < removedSize; i++)
        {
            tempSum += cardPoints[i];
        }
        int maxRes = sum - tempSum;
        for (int i = removedSize; i < n; i++)
        {
            tempSum -= cardPoints[i - removedSize];
            tempSum += cardPoints[i];
            int remainSum = sum - tempSum;
            maxRes = max(maxRes, remainSum);
        }
        return maxRes;
    }
};

// If constraints were less
class Solution
{
private:
    int func(int i, int j, vector<int> &cardPoints, int count, int k, vector<vector<int>> &dp)
    {

        if ((k < count) || (i >= (int)cardPoints.size()) || (j < 0) || (i > j))
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int caseOne = cardPoints[i] + func(i + 1, j, cardPoints, count + 1, k, dp);
        int caseTwo = cardPoints[j] + func(i, j - 1, cardPoints, count + 1, k, dp);
        return dp[i][j] = max(caseOne, caseTwo);
    }

public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int score = func(0, n - 1, cardPoints, 1, k, dp);
        return score;
    }
};