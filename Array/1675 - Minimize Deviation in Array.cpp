// Problem Link: https://leetcode.com/problems/minimize-deviation-in-array/

// Space Complexity: O(n)
// Time Complexity: O()

class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {
        set<int> st;
        for (int i = 0; i < nums.size(); i++)
        {
            if ((nums[i] % 2 != 0))
                st.insert(nums[i] * 2);
            else
                st.insert(nums[i]);
        }
        int maxElement = *st.rbegin();
        int minElement = *st.begin();
        int minDiff = maxElement - minElement;
        do
        {
            if ((maxElement % 2 == 0))
            {
                st.insert(maxElement / 2);
                st.erase(maxElement);
            }
            maxElement = *st.rbegin();
            minElement = *st.begin();
            minDiff = min(minDiff, maxElement - minElement);
        } while ((maxElement % 2 == 0));
        return minDiff;
    }
};