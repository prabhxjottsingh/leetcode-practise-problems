// Problem Link: https://leetcode.com/problems/3sum/
// Time Complexity:

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        if (nums.size() > 1 && nums[0] > 0)
            return {};
        int n = nums.size();
        for (int i = 0; i < n; i++)
            mp[nums[i]] = i;
        for (int i = 0; i < n - 2; i++)
        {
            // mp[nums[i]]--;
            if (nums[i] > 0)
                break;
            for (int j = i + 1; j < n - 1; j++)
            {
                // mp[nums[j]]--;
                if (mp[(-1) * (nums[i] + nums[j])] > j)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back((-1) * (nums[i] + nums[j]));
                    sort(temp.begin(), temp.end());
                    // if(find(ans.begin(), ans.end(), temp) == ans.end())
                    ans.push_back(temp);
                }
                // mp[nums[j]]++;
                j = mp[nums[j]];
            }
            i = mp[nums[i]];
            // mp[nums[i]]++;
        }
        return ans;
    }
};

// Time Complexity: O(N * N * log N)

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        set<vector<int>> resVec;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int start = i + 1;
            int end = n - 1;
            while (start < end)
            {
                int currSum = nums[i] + nums[start] + nums[end];
                if (currSum == 0)
                {
                    resVec.insert({nums[i], nums[start], nums[end]});
                    start += 1;
                    end -= 1;
                }
                else if (currSum > 0)
                    end--;
                else
                    start++;
            }
        }
        vector<vector<int>> vec;
        for (auto &a : resVec)
            vec.push_back(a);
        return vec;
    }
};