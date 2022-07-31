//Problem Link: https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/
//Time Complexity: O(N * M * log N);
//Space Complexity: O(N)

class Solution {
private:
    int helperFunc(priority_queue<int, vector<int>, greater<int>> &pq){
        priority_queue<int, vector<int>, greater<int>> newPq;
        if( pq.empty() )
            return 0;
        int minElem = pq.top();
        pq.pop();
        while( !pq.empty() && pq.top() >= minElem ){
            newPq.push(pq.top() - minElem);
            pq.pop();
        }
        while( !newPq.empty() && newPq.top() == 0 )
            newPq.pop();
        return (1 + helperFunc(newPq));
    }
    
public:
    int minimumOperations(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto &a : nums)
            pq.push(a);
        while( !pq.empty() && pq.top() == 0 )
            pq.pop();
        int countOperations = helperFunc(pq);
        return countOperations;
    }
};

//Time Complexity: O(N * log N)
//Space Complexity: O(N)

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> st;
        int n = nums.size();
        for(auto &a : nums){
            if( a == 0 )
                continue;
            st.insert(a);
        }
        return (int)st.size();
    }
};