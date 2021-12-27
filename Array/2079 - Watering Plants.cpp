//Tags: Array, Medium
//Problem Link: https://leetcode.com/problems/watering-plants/
//Time Compxity: O(n)

class Solution
{
public:
    int wateringPlants(vector<int> &plants, int capacity)
    {
        int steps = 0, n = plants.size(), capacityAlt = capacity;
        for (int i = 0; i < n; i++)
        {
            if (plants[i] <= capacityAlt)
            {
                steps++;
            }
            else
            {
                steps += i;
                steps += i + 1;
                capacityAlt = capacity;
            }
            capacityAlt -= plants[i];
        }
        return steps;
    }
};
