//tc: O(n)
//sc: O(n)

class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long rVal = 0;
        int i = 0;
        int j = nums.size() - 1;
        while( i < j ){
            string o = to_string(nums[i]);
            string t = to_string(nums[j]);
            long long val = stoi(o + t);
            rVal += val;
            cout << rVal << endl;
            i += 1;
            j -= 1;
        }
        if( i == j ) rVal += nums[i];
        return rVal;
    }
};
