// Problem Link: https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/

// Time Complexity: O(N^2)
// Space Complexity: O(1) -> Using Two Pointers

class Solution
{
public:
    int minMovesToMakePalindrome(string s)
    {
        int n = s.size();
        int left = 0, right = n - 1;
        int count = 0;
        while (left < right)
        {
            int tempLeft = left, tempRight = right, countLeft = 0, countRight = 0;

            while (s[left] != s[tempRight])
            {
                countRight++;
                tempRight--;
            }

            while (s[right] != s[tempLeft])
            {
                countLeft++;
                tempLeft++;
            }

            if (countLeft < countRight)
            {
                for (int i = tempLeft; i > left; i--)
                {
                    swap(s[i], s[i - 1]);
                }
                count += countLeft;
            }

            else
            {
                for (int i = tempRight; i < right; i++)
                {
                    swap(s[i], s[i + 1]);
                }
                count += countRight;
            }
            left++;
            right--;
        }
        return count;
    }
};