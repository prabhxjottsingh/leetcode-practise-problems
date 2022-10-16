// Problem Link: O()

// Space Complexity: O(2 * N)
// Time Complexity: O(N)

class Solution
{
private:
    int reverseOf(int x)
    {
        int num = 0;
        while (x)
        {
            int r = x % 10;
            num = num * 10 + r;
            x /= 10;
        }
        return num;
    }

public:
    int countDistinctIntegers(vector<int> &nums)
    {
        set<int> st;
        for (auto &a : nums)
        {
            st.insert(a);
            st.insert(reverseOf(a));
        }
        return (int)st.size();
    }
};