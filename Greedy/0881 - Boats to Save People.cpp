// Problem Link: https://leetcode.com/problems/boats-to-save-people/

// Time Complexity: O(N * log N)
// Space Complexity: O(1)

class Solution
{
public:
    int numRescueBoats(vector<int> &v, int limit)
    {
        sort(v.begin(), v.end());
        int n = v.size();
        int left = 0, right = n - 1, count = 0;
        while (left <= right)
        {
            if (v[left] + v[right] <= limit)
            {
                right--;
                left++;
            }
            else
            {
                right--;
            }
            count++;
        }
        return count;
    }
};

// Time Complexity: O(N*Log N + N) -> Sorting and iterating
// Space Complexity: O(N) -> Use of set container

class Solution
{
public:
    int numRescueBoats(vector<int> &v, int limit)
    {
        sort(v.begin(), v.end());
        int n = v.size();
        int left = 0, right = n - 1, count = 0;
        set<int> st;
        while (left < right)
        {
            if (v[left] + v[right] <= limit)
            {
                count++;
                st.insert(left);
                st.insert(right);
                right--;
                left++;
            }
            else
            {
                right--;
            }
        }
        count += n - st.size();
        return count;
    }
};