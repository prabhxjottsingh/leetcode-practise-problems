//time Complexity: O(1)
//sc: O(1)

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int sum = min(k, numOnes);
        k -= min(k, numOnes);
        k -= min(k, numZeros);
        sum -= min(k, numNegOnes);
        return sum;
    }
};
