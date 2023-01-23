// tc: O(n)
// sc: O(n)

class Solution
{
public:
    long long minOperations(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<int> newVec;
        if (k == 0)
        {
            if (nums1 == nums2)
                return 0;
            return -1;
        }
        int n = nums1.size();
        for (int i = 0; i < n; i++)
        {
            int diff = nums1[i] - nums2[i];
            if (diff % k != 0)
                return -1;
            newVec.push_back(diff);
        }
        sort(newVec.begin(), newVec.end());
        int i = 0;
        int j = newVec.size() - 1;
        long long count = 0;
        while (i < j)
        {
            int &valOne = newVec[i];
            int &valTwo = newVec[j];
            if ((valOne > 0 && valTwo > 0) || (valOne < 0 && valTwo < 0))
                return -1;
            if (valOne == 0)
            {
                i++;
                continue;
            }
            if (valTwo == 0)
            {
                j--;
                continue;
            }
            int caseOne = abs(valOne) / k;
            int caseTwo = abs(valTwo) / k;
            count += min(caseOne, caseTwo);
            if (caseOne < caseTwo)
            {
                i++;
                valOne = 0;
                valTwo -= k * caseOne;
            }
            else if (caseTwo < caseOne)
            {
                j--;
                valTwo = 0;
                valOne += k * caseTwo;
            }
            else
            {
                i++;
                j--;
                valOne = 0;
                valTwo = 0;
            }
        }
        sort(newVec.begin(), newVec.end());
        if (newVec[0] == newVec[n - 1] && newVec[0] == 0)
            return count;
        return -1;
    }
};