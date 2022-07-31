//Problem Link: https://leetcode.com/problems/range-sum-query-mutable/
//Time Complexity: O(N * log N)
//Space Complexity: O(4 * n)

class NumArray {
private:
    vector<int> segTree;
    long long int sz;
    
    void segTreeConstructor(int n){
        segTree.resize(4 * n + 1);
        sz = n;
    }
    
    void buildSegtree(long long int idx, int low, int high, vector<int> &arr){
        if( low == high ){
            segTree[idx] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        buildSegtree(2 * idx + 1, low, mid, arr);
        buildSegtree(2 * idx + 2, mid + 1, high, arr);
        segTree[idx] = segTree[2 * idx + 1] + segTree[2 * idx + 2]; 
    }

    int query(long long int idx, int low, int high, int l, int r){
        if( r < low || l > high )
            return 0;
        if( l <= low && r >= high )
            return segTree[idx];
        int mid = (low + high) / 2;
        int leftSum = query(2 * idx + 1, low, mid, l, r);
        int rightSum = query(2 * idx + 2, mid + 1, high, l, r);
        return leftSum + rightSum;
    }

    void update(long long int idx, int low, int high, int i, int val){
        if( low == high ){
            segTree[idx] = val;
            return;
        }
        int mid = (low + high) / 2;
        if( i <= mid )
            update(2 * idx + 1, low, mid, i, val);
        else
            update(2 * idx + 2, mid + 1, high, i, val);
        segTree[idx] = segTree[2 * idx + 1] + segTree[2 * idx + 2];
    }
    
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        segTreeConstructor(n);
        buildSegtree(0, 0, n - 1, nums);
    }
    
    void update(int index, int val) {
        update(0, 0, sz - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return query(0, 0, sz - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */