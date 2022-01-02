//Tags: Medium
//Problem Link: https://leetcode.com/problems/destroying-asteroids/
//Time Complexity: O(nlog n)

class Solution
{
public:
    bool asteroidsDestroyed(int mass, vector<int> &asteroids)
    {
        sort(asteroids.begin(), asteroids.end());
        int n = asteroids.size();
        long long massTwo = mass;
        for (int i = 0; i < n; i++)
        {
            if (massTwo >= asteroids[i])
                massTwo += asteroids[i];
            else
                return false;
        }
        return true;
    }
};