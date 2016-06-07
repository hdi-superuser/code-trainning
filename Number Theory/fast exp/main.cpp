#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll fast_exp(ll a, ll n) {
    ll res = 1, x = a;
    for (ll p = n; p; p >>= 1, x *= x)
        if (p & 1) res *= x;
    return res;
}

ll standard_exp(ll a, ll n) {
    if (n == 0) return 1;
    if (n == 1) return a;
    ll x = standard_exp(a, n/2);
    if (n & 1) return x*x*a;
    return x*x;
}

ll slow_exp(ll a, ll n) {
    ll x = 1;
    for (ll i = 1; i <= n; i++) x *= a;
    return x;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    cout << fast_exp(2, 4) << endl << standard_exp(2, 4);
    return 0;
}
