// Time Complexity: O(N ^ 2 * log N)
// Space Complexity: O(N)

// TLE

class Solution
{
public:
    int LongestBitonicSequence(vector<int> nums)
    {
        int maxLen = 1;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            temp.push_back(nums[0]);
            for (int j = 0; j < i; j++)
            {
                if (nums[j] > temp.back())
                    temp.push_back(nums[j]);
                else
                {
                    int idx = lower_bound(temp.begin(), temp.end(), nums[j]) - temp.begin();
                    temp[idx] = nums[j];
                }
            }
            vector<int> tempTwo;
            tempTwo.push_back(nums[n - 1]);
            for (int j = n - 1; j >= i; j--)
            {
                if (nums[j] > tempTwo.back())
                    tempTwo.push_back(nums[j]);
                else
                {
                    int idx = lower_bound(tempTwo.begin(), tempTwo.end(), nums[j]) - tempTwo.begin();
                    tempTwo[idx] = nums[j];
                }
            }
            while (temp.size() && tempTwo.size() && temp.back() == tempTwo.back())
                temp.pop_back();
            maxLen = max(maxLen, (int)temp.size() + (int)tempTwo.size());
        }
        return maxLen;
    }
};

// Time Complexity: O(N * log N)
// Space Complexity: O(N)

class Solution
{
public:
    int LongestBitonicSequence(vector<int> nums)
    {
        int n = nums.size();
        int left[n];
        int right[n];
        int maxLen = 1;
        vector<int> temp;
        temp.push_back(nums[0]);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > temp.back())
                temp.push_back(nums[i]);
            else
            {
                int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[idx] = nums[i];
            }
            left[i] = temp.size();
        }
        temp.clear();
        temp.push_back(nums[n - 1]);
        for (int i = n - 1; i > -1; i--)
        {
            if (nums[i] > temp.back())
                temp.push_back(nums[i]);
            else
            {
                int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[idx] = nums[i];
            }
            right[i] = temp.size();
        }
        for (int i = 0; i < n; i++)
        {
            maxLen = max(maxLen, left[i] - 1 + right[i]);
        }
        return maxLen;
    }
};
