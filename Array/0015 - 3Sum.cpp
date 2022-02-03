//Problem Link: https://leetcode.com/problems/3sum/
//Time Complexity:

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
            //mp[nums[i]]--;
            if (nums[i] > 0)
                break;
            for (int j = i + 1; j < n - 1; j++)
            {
                //mp[nums[j]]--;
                if (mp[(-1) * (nums[i] + nums[j])] > j)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back((-1) * (nums[i] + nums[j]));
                    sort(temp.begin(), temp.end());
                    //if(find(ans.begin(), ans.end(), temp) == ans.end())
                    ans.push_back(temp);
                }
                //mp[nums[j]]++;
                j = mp[nums[j]];
            }
            i = mp[nums[i]];
            //mp[nums[i]]++;
        }
        return ans;
    }
};