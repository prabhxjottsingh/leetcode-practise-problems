// Problem Link: https://atcoder.jp/contests/abc282/tasks/abc282_e

// Time Complexity: O(N ^ 2 log N)
// Using the concept of Maximum Spanning Tree, and Binary Exponentiation

#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define ll long long
#define wishOneDay                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
#define nline '\n'

ll m;

class DSU
{
public:
    vector<ll> par;
    vector<ll> sz;

    DSU(ll n)
    {
        par.resize(n);
        sz.resize(n, 1);
        for (ll i = 0; i < n; i++)
            par[i] = i, sz[i] = 1;
    }

    ll findPar(ll n)
    {
        if (n == par[n])
            return n;
        return par[n] = findPar(par[n]);
    }

    void Union(ll a, ll b)
    {
        a = findPar(a);
        b = findPar(b);
        if (a != b)
            par[b] = a;
    }
};

ll calPower(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll num = calPower(a, b / 2);
    if (b & 1)
        return ((((a % m) * (num % m)) % m) * (num % m)) % m;
    else
        return (((num % m) * (num % m)) % m);
}

void solve()
{
    ll n;
    cin >> n >> m;
    vector<ll> arr(n);
    for (auto &a : arr)
        cin >> a;
    priority_queue<pair<ll, pair<ll, ll>>> pq;
    DSU disjollSt(n);
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            ll newVal = (calPower(arr[i], arr[j]) % m + calPower(arr[j], arr[i]) % m) % m;
            pq.push({newVal, {i, j}});
        }
    }
    ll score = 0;
    while (!pq.empty())
    {
        auto front = pq.top();
        pq.pop();
        ll a = front.second.first;
        ll b = front.second.second;
        ll add = front.first;
        // cout << a << ", " << b << " -> " << add << endl;
        if (disjollSt.findPar(a) != disjollSt.findPar(b))
            score += add, disjollSt.Union(a, b);
    }
    cout << score;
}

int main()
{

    wishOneDay

        ll tc = 1;
    // cin >> tc;
    while (tc--)
        solve(), cout << nline;
    return 0;
}

// Dunzo Test Problem - XOR Maximum by n - 1 operations
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll m;

class DSU
{
public:
    vector<ll> par;
    vector<ll> sz;

    DSU(ll n)
    {
        par.resize(n);
        sz.resize(n, 1);
        for (ll i = 0; i < n; i++)
            par[i] = i, sz[i] = 1;
    }

    ll findPar(ll n)
    {
        if (n == par[n])
            return n;
        return par[n] = findPar(par[n]);
    }

    void Union(ll a, ll b)
    {
        a = findPar(a);
        b = findPar(b);
        if (a != b)
            par[b] = a;
    }
};

int main()
{
    ll n;
    cin >> n >> m;
    vector<ll> arr(n);
    for (auto &a : arr)
        cin >> a;
    priority_queue<pair<ll, pair<ll, ll>>> pq;
    DSU disjointSt(n);
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            ll newVal = arr[i] ^ arr[j];
            pq.push({newVal, {i, j}});
        }
    }
    ll score = 0;
    while (!pq.empty())
    {
        auto front = pq.top();
        pq.pop();
        ll a = front.second.first;
        ll b = front.second.second;
        ll addScore = front.first;
        if (disjointSt.findPar(a) != disjointSt.findPar(b))
        {
            score += addScore;
            disjointSt.Union(a, b);
        }
    }
    cout << score;
}