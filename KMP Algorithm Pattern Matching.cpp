//SPOJ Problem Link: https://www.spoj.com/problems/NAJPF/

//Time Complexity: O(n + m)
//space Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define ll long long
#define wishOneDay ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define nline '\n'

void solve(){

    string a, b;
    cin >> a >> b;

    int i = 1, len = 0, n = a.size(), m = b.size();

    int lps[m];
    memset(lps, 0, sizeof(lps));

    while( i < m ){
        if( b[i] == b[len] ){
            ++len;
            lps[i] = len;
            i++;
        }
        else{
            if( len > 0 )
                len = lps[len - 1];
            else{
                lps[i] = 0;
                i++;
            }
        }
    }

    int cnt = 0;
    i = 0;
    int j = 0;
    vector<int> rIdx;
    while( i < n ){
        if( a[i] == b[j] ) i++, j++;
        else{
            if( j != 0 ) j = lps[j - 1];
            else i++;
        }
        if( j == m ) cnt += 1, rIdx.push_back(i - m + 1);
    }
    if( !rIdx.size() ){
        cout << "Not Found" << endl;
        return;
    }
    cout << rIdx.size() << endl;
    for(auto &a : rIdx)
        cout << a << " ";
    cout << endl;
}

int main(){

    wishOneDay

    int tc = 1;
    cin >> tc;
    while( tc-- ) solve(), cout << nline;
    return 0;

}

//Rabin - Karp Algorithm
#include<bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define ll long long
#define wishOneDay ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define nline '\n'

const int N = 1e6 + 7;
const int p = 31;
ll hsh[N];
ll powr[N];
const int mod = 1e9 + 7;

ll getHashVal(ll l, ll r){
    if( l > 0 ) l -= 1;
    else return hsh[r];
    return ((hsh[r] - hsh[l]) + mod) % mod;
}

void solve(){

    string a, b;
    cin >> a >> b;

    ll dhv = b[0] - 'a' + 1, pwr = p;
    int n = a.size(), m = b.size();

    for(int i = 1; i < m; i++)
        dhv = dhv + (b[i] - 'a' + 1) * pwr, pwr *= p, dhv %= mod, pwr %= mod;

    hsh[0] = a[0] - 'a' + 1;
    pwr = p;
    powr[0] = 1;
    for(int i = 1; i < n; i++){
        hsh[i] = hsh[i - 1] + (a[i] - 'a' + 1) * pwr;
        hsh[i] %= mod;
        powr[i] = pwr;
        pwr *= p;
        pwr %= mod;
    }
    vector<int> rIdx;
    for(int i = m - 1; i < n; i++){
        if( getHashVal(i - m + 1, i) == (powr[i - m + 1] * dhv) % mod )
            rIdx.push_back(i - m + 2);
    }
    if( !rIdx.size() ){
        cout << "Not Found" << endl;
        return;
    }
    cout << rIdx.size() << endl;
    for(auto &a : rIdx)
        cout << a << " ";
    cout << endl;

}

int main(){

    wishOneDay

    int tc = 1;
    cin >> tc;
    while( tc-- ) solve(), cout << nline;
    return 0;

}
