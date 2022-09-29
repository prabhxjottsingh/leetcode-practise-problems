//Problem Link: https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

//time Complexity: O(N)
//Space Complexity: O(1)

class Solution
{
public:
    void sort012(int a[], int n)
    {
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high)
        {
            if (a[mid] == 0)
                swap(a[mid], a[low]), low += 1, mid += 1;
            else if (a[mid] == 2)
                swap(a[mid], a[high]), high -= 1;
            else
                mid += 1;
        }
    }
};