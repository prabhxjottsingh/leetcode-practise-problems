// Problem Link: https://leetcode.com/problems/range-frequency-queries/

// Time Complexity: O(log N) -> per qeury
// Space Complexity: O(N)

class RangeFreqQuery
{
private:
    vector<vector<int>> pre;

    int helperBinarySearch(int x, int value)
    {
        int low = 0, high = pre[value].size() - 1, count = 0;
        while (high > low)
        {
            int mid = (high + low) / 2;
            if (pre[value][mid] >= x)
            {
                high = mid;
            }
            else
            {
                count = mid + 1;
                low = mid + 1;
            }
        }
        return count;
    }

public:
    RangeFreqQuery(vector<int> &arr) : pre(100003)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            pre[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value)
    {
        if (pre[value].size() == 0)
        {
            return 0;
        }
        int countLeft = helperBinarySearch(left, value);
        int countRight = helperBinarySearch(right, value);
        if (pre[value][countRight] > right)
            countRight--;
        if (pre[value][countLeft] < left)
            countLeft++;
        int finalCount = countRight - countLeft + 1;
        return finalCount;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */