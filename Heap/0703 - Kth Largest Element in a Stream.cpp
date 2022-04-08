// Problem Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/

// Time Complexity: O(N * log N)
// Space Complexity: O(N)

class KthLargest
{
private:
    priortiy_queue < int, vector<int>, greater<int> minHeap;
    int K;

public:
    KthLargest(int k, vector<int> &nums)
    {
        K = k;
        for (auto &a : nums)
        {
            minHeap.push(a);
            if (minHeap.size() > k)
                minHeap.pop();
        }
    }

    int add(int val)
    {
        minHeap.push(val);
        if (minHeap.size() > K)
            minHeap.pop();
        return minHeap.top() :
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */