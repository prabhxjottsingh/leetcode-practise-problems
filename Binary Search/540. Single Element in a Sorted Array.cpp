//tc: O(log N)
//sc: O(1)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int resIdx = 0;
        while( low <= high ){
            int mid = low + (high - low) / 2;
            int val = nums[mid];
            if( mid > 0 && nums[mid - 1] == val ){
                if( mid % 2 != 0 )
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            else if( mid < n - 1 && nums[mid + 1] == val ){
                if( mid % 2 != 0 )
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
                return nums[mid];
        }
        return -1;
    }
};
