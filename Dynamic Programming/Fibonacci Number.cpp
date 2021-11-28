//Difficulty: Easy\
//Space Complexity: O(1)
//Time Complxity: O(2^n) or exponential - Recursion

class Solution {
public:
    int fib(int n) {
        if(n<2)
            return n;
        else 
            return (fib(n-1) + fib(n-2));
    }
};

//Time Complxity: Linear using DP

class Solution {
public:
    int fib(int n) {
        int f[n+1];
        int f[0] = 0, f[1] = 1;
        for(int i=2; i<=n; i++){
            f[i] = f[i-1] + f[i-2];
        }
        return f[n];
    }
};