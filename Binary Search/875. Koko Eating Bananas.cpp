//Tags: Medium, Binary Search
//Problem Link: https://leetcode.com/problems/koko-eating-bananas/
//Time Complexity: O(log N)
//Space Complexity: O(1)

class Solution
{
private:
    bool isSufficient(vector<int> piles, int h, int k)
    {
        int count = 0;
        int n = piles.size();
        for (int i = 0; i < n; i++)
        {
            count += piles[i] / k;
            if (piles[i] % k != 0)
                count++;
        }
        //cout << k << " "<< count << endl;
        if (count <= h)
            return true;
        else
            return false;
    }

public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size();
        int low = 1, high = *max_element(piles.begin(), piles.end()), mid, ans;
        while (high - low > 1)
        {
            mid = (high + low) / 2;
            if (isSufficient(piles, h, mid))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        if (isSufficient(piles, h, low))
            return low;
        return high;
    }
};