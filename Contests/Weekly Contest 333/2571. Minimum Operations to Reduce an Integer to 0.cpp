//tc: O(log N)
//sc: O(1)

class Solution {
private:
    int f(int n){
        if( !n ) return 0;
        int a = log2(n);
        int b = log2(n) + 1;
        int x = abs(pow(2, a) - n);
        int y = abs(pow(2, b) - n);
        return 1 + f(min(x, y));
    }

public:
    int minOperations(int n) {
        return f(n);
    }
};
