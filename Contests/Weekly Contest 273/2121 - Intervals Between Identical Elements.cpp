// Problem Link: https://leetcode.com/problems/intervals-between-identical-elements/

/// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
public:
    vector<long long> getDistances(vector<int> &arr)
    {
        map<int, long long> freq, finalFreq;
        map<int, vector<long long>> sumMap;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (sumMap.count(arr[i]) == 0)
            {
                sumMap[arr[i]].push_back(i);
            }
            else
            {
                sumMap[arr[i]].push_back(sumMap[arr[i]][sumMap[arr[i]].size() - 1] + i);
            }
            finalFreq[arr[i]]++;
        }
        vector<long long> res;
        for (int i = 0; i < n; i++)
        {
            freq[arr[i]]++;
            long long leftSum = abs(((freq[arr[i]] - 1) * i) - (sumMap[arr[i]][freq[arr[i]] - 1] - i));
            long long rightSum = abs((((finalFreq[arr[i]] - freq[arr[i]]) * i) - abs((sumMap[arr[i]][freq[arr[i]] - 1]) - sumMap[arr[i]][sumMap[arr[i]].size() - 1])));
            res.push_back(rightSum + leftSum);
        }
        return res;
    }
};