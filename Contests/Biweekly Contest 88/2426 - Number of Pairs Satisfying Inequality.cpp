// Problem Link: https://leetcode.com/problems/number-of-pairs-satisfying-inequality/

// Time Complexity: O(N * log N)
// Space Complexity: O(N)

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_multiset;

class Solution
{
public:
    long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int diff)
    {
        long long count = 0;
        ordered_multiset st;
        int n = nums1.size();
        for (int i = 0; i < n; i++)
        {
            int diffAgain = nums1[i] - nums2[i] + diff + 1;
            count += st.order_of_key(diffAgain);
            diffAgain -= diff + 1;
            st.insert(diffAgain);
        }
        return count;
    }
};