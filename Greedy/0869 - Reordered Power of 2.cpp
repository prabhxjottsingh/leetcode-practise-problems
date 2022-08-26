// Problem Link: https://leetcode.com/problems/reordered-power-of-2/

// Time Complexity: O(N * log N)
// Space Complexity: O(1)

class Solution
{
private:
    set<string> powerOfTwo;

    void insertInSet(long long int num)
    {
        string str = to_string(num);
        sort(str.begin(), str.end());
        powerOfTwo.insert(str);
    }

    void helperFunc()
    {
        long long int res = 1;
        while (res <= 1e9)
        {
            insertInSet(res);
            res *= 2;
        }
    }

public:
    bool reorderedPowerOf2(int n)
    {
        helperFunc();
        string str = to_string(n);
        sort(str.begin(), str.end());
        return powerOfTwo.count(str);
    }
};