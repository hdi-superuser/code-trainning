#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;
const ll BASE = 1000000007;

int N, p, t;
ll memo[10001][21][5];

ll dp(int n, int x, int just) {
    if (x >= p) x = p;
    if (just == 2) {
        if (n == 0) return 0;
        return dp(n-1, x+1, 1);
    } else {
        if (n == 0) return 1;
        if (memo[x][just][n] != -1) return memo[x][just][n];
        ll sum = dp(n-1, x+1, 1) * 2;
        if (just == 1) sum += dp(n-1, x+1, 2);
        if (x >= p) sum += dp(n-1, 0, 0);
        sum += dp(n-1, x+1, 0) * (t-4);
        return memo[x][just][n] = sum % BASE;
    }
}

#include <bits/stdc++.h>
#define C p][Just][p0][Just0][Stop
#define long long long

const long M = 1000000007;
map<int, int> G[21][3][21][3][2];

long g(int n, int p, int Just, int p0, int Just0, bool Stop) {
    if (p>=::p) p=::p;
    if (n%2==1 || n==0) {
        if (Just==2) {
            if (n==0) return Stop ? 0 : p==p0 && Just==Just0;
            return g(n-1, p+1, 1, p0, Just0, Stop);
        } else {
            if (n==0) return Stop ? 1 : p==p0 && Just==Just0;
            if (G[C].count(n)) return G[C][n];
            long Sum = g(n-1, p+1, 1, p0, Just0, Stop) * 2;
            if (Just==1) Sum += g(n-1, p+1, 2, p0, Just0, Stop);
            if (p>=::p) Sum += g(n-1, 0, 0, p0, Just0, Stop);
            Sum += g(n-1, p+1, 0, p0, Just0, Stop) * (t-4);
            return G[C][n] = Sum % M;
        }
    } else {
        if (G[C].count(n)) return G[C][n];
        long Sum = 0;
        for (int i=0; i<=::p; i++)
        for (int k=0; k<=2; k++) {
            long G1 = g(n/2, p, Just, i, k, false);
             long G2 = g(n/2, i, k, p0, Just0, Stop);
            Sum += G1*G2;
        }
        return G[C][n] = Sum % M;
     }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> N >> p >> t;
    memset(memo, -1, sizeof memo);
    cout << dp(N, p, 0) << endl;
    cout << g(N, ::p, 0, rand()%21, rand()%3, true) << endl;

    return 0;
}
