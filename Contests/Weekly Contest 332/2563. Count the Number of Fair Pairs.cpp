//tc: O(n * log N)
//sc: O(n)

class Solution {
private:
    int bsUpper(vector<int> &nums, int i, int x, int r){
        int low = i;
        int high = nums.size() - 1;
        int res = -1;
        while( low <= high ){
            int mid = low + (high - low) / 2;
            int nw = nums[mid] + x;
            if( nw <= r ){
                res = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return res;
    }

    int bsLower(vector<int> &nums, int i, int x, int r){
        int low = i;
        int high = nums.size() - 1;
        int res = -1;
        while( low <= high ){
            int mid = low + (high - low) / 2;
            int nw = nums[mid] + x;
            if( nw < r )
                low = mid + 1;
            else if( nw >= r ){
                res = mid;
                high = mid - 1;
            }
        }
        return res;
    }

public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        // for(auto &a : nums)
        //     cout << a << " ";
        // cout << endl;
        long long count = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int u = bsUpper(nums, i + 1, nums[i], upper);
            int l = bsLower(nums, i + 1, nums[i], lower);
            // cout << nums[i] << " -> " << l << " - " << u << " = ";
            if( u == -1 || l == -1 ){
                // cout << count << endl;
                continue;
            }
            int diff = u - l + 1;
            count += diff;
            // cout << count << endl;
        }
        return count;
    }
};
