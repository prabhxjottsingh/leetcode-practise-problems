*Dynamic Programming* is an optimized approach for using recursion, wherever we have used recursion we can optimize the 
code with the help of DP.

for example first I wrote the code for "N-th Tribonacci Number", which gave me TLE error, this means the solution I have
used or logic I have built is right, now I have to use DP instead of plain recursion to avoid this TLE error

factorial of a number using DP;


this code follows bottom up approach, as the starting condition is base condition
```
int dp[MAXN];

int dp[0] = 1; //base case

int main(){
    for(int i=1; i<n; i++){
        dp[i] = dp[i-1]*(i);
    }
}
```
