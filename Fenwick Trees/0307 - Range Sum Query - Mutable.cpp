// Problem Link: https://leetcode.com/problems/range-sum-query-mutable/

// time Complexity: O(n * log N)
// Space Complexity: O(N)

class NumArray
{
private:
    vector<int> bit;
    vector<int> arr;
    int n;

    void updateVal(int i, int x)
    {
        while (i <= n)
        {
            bit[i] += x;
            i += (i & -i);
        }
    }

    long long sum(int i)
    {
        long ans = 0;
        while (i > 0)
        {
            ans += bit[i];
            i -= (i & -i);
        }
        return ans;
    }

public:
    NumArray(vector<int> &nums)
    {
        n = nums.size();
        arr.resize(n);
        for (int i = 0; i < n; i++)
            arr[i] = nums[i];
        bit.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            updateVal(i, nums[i - 1]);
        }
    }

    void update(int index, int val)
    {
        updateVal(index + 1, val - arr[index]);
        arr[index] = val;
    }

    int sumRange(int left, int right)
    {
        int sumQuery = sum(right + 1) - sum(left);
        return sumQuery;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */