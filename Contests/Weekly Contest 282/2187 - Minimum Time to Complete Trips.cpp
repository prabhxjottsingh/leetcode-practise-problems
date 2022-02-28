// Problem Link: https://leetcode.com/problems/minimum-time-to-complete-trips/

// Time Complexity: O(N * Log N) -> used Binary Search

// Space Complexity: O(1)

class Solution
{
private:
    bool check(long long int k, vector<int> v, int totalTrips)
    {
        int time = 0;
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            time += (k / v[i]);
            if (time >= totalTrips)
                return true;
        }
        return false;
    }

public:
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        int n = time.size();
        long long int ans = INT_MAX;
        long long int low = 0, high = (long long)totalTrips * (*min_element(time.begin(), time.end()));
        while (high >= low)
        {
            long long int mid = (low + high) / 2;
            if (check(mid, time, totalTrips))
            {
                high = mid - 1;
                ans = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};