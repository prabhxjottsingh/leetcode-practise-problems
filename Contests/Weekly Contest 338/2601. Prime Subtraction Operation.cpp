//tc: O(n * max(a))
//sc: O(1000)

class Solution {
private:
    bool isPrime(int x){
        for(int i = 2; i <= sqrt(x); i++){
            if( x % i == 0 ) return 0;
        }
        return 1;
    }

public:
    bool primeSubOperation(vector<int>& nums) {
        int prev = -1;
        for(auto &a : nums){
            int newA = 1e9;
            for(int i = a - 1; i > 1; i--){
                if( isPrime(i) && a - i > prev ){
                    newA = min(newA, a - i);
                }
            }
            a = min(a, newA);
            if( a <= prev ) return 0;
            prev = a;
        }
        return 1;
    }
};
