//Problem Link: https://leetcode.com/problems/maximum-performance-of-a-team/

//Time Complexity: O(N * log N)
//space Complexity: O(K)


class Solution
{
private:
    static const int mod = 1e9 + 7;

public:
    int maxPerformance(int n, vector<int> &spe, vector<int> &eff, int k)
    {
        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i++)
            vp.emplace_back(eff[i], spe[i]);
        sort(vp.rbegin(), vp.rend());
        long long int maxPerf = 0;
        long long int totSpee = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++)
        {
            long long int tempSpe = vp[i].second;
            long long int tempEff = vp[i].first;
            if (pq.size() < k)
            {
                totSpee += tempSpe;
                pq.push(tempSpe);
            }
            else
            {
                totSpee -= pq.top();
                pq.pop();
                totSpee += tempSpe;
                pq.push(tempSpe);
            }
            maxPerf = max(maxPerf, ((totSpee) * (tempEff)));
        }
        return maxPerf % mod;
    }
};