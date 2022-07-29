//Problem Link: https://leetcode.com/problems/fair-candy-swap/
//Time Complexity: O( (N * log N) + (M * log M) + (N * log M or M * log N) )
//Space Complexity: O(1)

class Solution {
private:
    bool isPresent(vector<int> &nums, int target){
        int low = 0, high = nums.size() - 1;
        while( low <= high ){
            int mid = (low + high) / 2;
            if( nums[mid] == target )
                return true;
            else if( nums[mid] < target )
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
    
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int aliceSum = 0;
        int bobSum = 0;
        int n = aliceSizes.size();
        int m = bobSizes.size();
        sort( aliceSizes.begin(), aliceSizes.end() );
        sort( bobSizes.begin(), bobSizes.end() );
        for(auto &a : aliceSizes){
            aliceSum += a;
        }
        for(auto &a : bobSizes){
            bobSum += a;
        }
        int totSum = bobSum + aliceSum;
        int reqSum = totSum / 2;
        bool flag = 0;
        if( reqSum < aliceSum ){
            for(int i = 0; i < m; i++){
                int shouldBePresentInAlice = (aliceSum - reqSum) + bobSizes[i];
                if( isPresent(aliceSizes, shouldBePresentInAlice) ){
                    return {shouldBePresentInAlice, bobSizes[i]};
                }
            }
        }
        else{
            for(int i = 0; i < n; i++){
                int shouldBePresentInBob = (bobSum - reqSum) + aliceSizes[i];
                cout << aliceSizes[i] << " " << shouldBePresentInBob << endl;
                if( isPresent(bobSizes, shouldBePresentInBob) ){
                    return {aliceSizes[i], shouldBePresentInBob};
                }
            }
        }
        return {-1, -1};
    }
};