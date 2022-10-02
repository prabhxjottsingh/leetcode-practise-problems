// Problem Link: https://leetcode.com/problems/find-k-closest-elements/

// Time Complexity: O(N * log N + K * log K)
// Space Complexity: O(N)

class Solution
{
private:
    static bool comp(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    }

public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        vector<pair<int, int>> dist;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            dist.emplace_back(arr[i], abs(arr[i] - x));
        }
        sort(dist.begin(), dist.end(), comp);
        vector<int> resVec;
        for (int i = 0; i < k; i++)
            resVec.push_back(dist[i].first);
        sort(resVec.begin(), resVec.end());
        return resVec;
    }
};

// Time Complexity: O(k * log K)
// Space Complexity: O(k)

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int n = arr.size();
        priority_queue<pair<int, int>> pq;
        vector<int> resVec;
        reverse(arr.begin(), arr.end());
        for (auto &a : arr)
        {
            pq.push({abs(a - x), a});
            if (pq.size() > k)
                pq.pop();
        }
        while (!pq.empty())
        {
            resVec.push_back(pq.top().second);
            pq.pop();
        }
        sort(resVec.begin(), resVec.end());
        return resVec;
    }
};

// Time Complexity: O(N * log N)
// Space Complexity: O(1)

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int start = 0;
        int end = (int)arr.size() - 1;
        while (end - start + 1 > k)
        {
            int distFront = abs(x - arr[start]);
            int distRear = abs(x - arr[end]);
            if (distFront <= distRear)
                end -= 1;
            else
                start += 1;
        }
        vector<int> resVec;
        for (int i = start; i <= end; i++)
            resVec.push_back(arr[i]);
        return resVec;
    }
};