#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;
const int MAX = 1000001;

int N, L;
ll memo[11][11][MAX];

ll dp(int n, int h, int x, int d) {
    if (h < 0 || h > L) return 0;
    if (n == 0) return (h == x);
    if (memo[h][x][d] != -1) return memo[h][x][d];
    ll ans = 0;
    if (n & 1)
        for (int i = 0; i <= L; i++) ans += dp(n/2, h, i, d+1) * dp(n/2, i, x, d+1);
    else
        ans = dp(n-1, h-1, x, d+1) + dp(n-1, h+1, x, d+1);
    memo[h][x][d] = ans;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> N >> L;
    memset(memo, -1, sizeof memo);
    cout << dp(N, 0, 0, 0);

    return 0;
}
