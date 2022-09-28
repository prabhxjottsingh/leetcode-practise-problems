// Problem Link: https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/

// Time Complexity: O(N ^ 3)
// Space Complexity: O(N)

class Solution
{
public:
    int countTriplets(vector<int> &arr)
    {
        int n = arr.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int k = i + 1; k < n; k++)
            {
                int len = k - i + 1;
                vector<int> leftXor(len, 0);
                leftXor[i % len] = arr[i];
                for (int j = i + 1; j <= k; j++)
                    leftXor[j % len] = leftXor[(j - 1) % len] ^ arr[j];
                vector<int> rightXor(len, 0);
                rightXor[k % len] = arr[k];
                for (int j = k - 1; j > i; j--)
                    rightXor[j % len] = arr[j] ^ rightXor[(j + 1) % len];
                for (int j = i + 1; j <= k; j++)
                {
                    if (leftXor[(j - 1) % len] == rightXor[(j) % len])
                        count += 1;
                }
            }
        }
        return count;
    }
};