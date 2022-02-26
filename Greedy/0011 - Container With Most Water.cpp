// Code Link: https://leetcode.com/problems/container-with-most-water/

// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    int maxArea(vector<int> &height)
    {

        int size = height.size();
        int left = 0, right = size - 1;
        int maxArea = 0;
        while (left < right)
        {
            int minHeight = min(height[left], height[right]);
            int length = (right - left);
            maxArea = max(maxArea, (minHeight * (length)));

            while ((height[left] <= minHeight) && (left < right))
            {
                left++;
            }
            while ((height[right] <= minHeight) && (left < right))
            {
                right--;
            }
        }
        return maxArea;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    int maxArea(vector<int> &height)
    {

        int size = height.size();
        int left = 0, right = size - 1;
        int maxArea = 0;
        while (left < right)
        {
            int minHeight = min(height[left], height[right]);
            int length = (right - left);
            maxArea = max(maxArea, (minHeight * (length)));

            if ((height[left] <= minHeight))
            {
                left++;
            }
            else if ((height[right] <= minHeight))
            {
                right--;
            }
        }
        return maxArea;
    }
};