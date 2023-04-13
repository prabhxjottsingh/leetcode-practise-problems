//Time Complexity: O(n)
//space Complexiity: O(n)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size();
        vector<int> rVec;
        for(int i = 0; i < k; i++){
            if( !dq.empty() && nums[dq.front()] <= nums[i] )
                dq.push_front(i);
            else{
                while( !dq.empty() && nums[dq.back()] <= nums[i] ) dq.pop_back();
                dq.push_back(i);
            }
            // printDq(dq, nums);
        }
        rVec.push_back(nums[dq.front()]);
        for(int i = k; i < n; i++){
            while( !dq.empty() && dq.front() <= i - k ) dq.pop_front();
            if( !dq.empty() && nums[dq.front()] <= nums[i] )
                dq.push_front(i);
            else{
                while( !dq.empty() && nums[dq.back()] <= nums[i] ) dq.pop_back();
                dq.push_back(i);
            }
            rVec.push_back(nums[dq.front()]);
            // printDq(dq, nums);
        }
        return rVec;
    }
};
