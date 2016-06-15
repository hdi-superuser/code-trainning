#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>


using namespace std;

const int maxN = 5*100001;
const long long INF = trunc(1e18);

int N;
long long t[maxN], p[maxN];
long long dp[maxN], tree[4*maxN+1], id[maxN];

void Build(int x, int L, int R) {
    if (L == R) id[L] = x;
    else {
        int mid = (L + R) >> 1;
        Build(2*x, L, mid);
        Build(2*x+1, mid+1, R);
    }
}

void Update(int x, long long val) {
    int node = id[x];
    while (node) tree[node] = min(tree[node], val), node /= 2;
}

long long Get(int x, int L, int R, int u, int v) {
    if (u > R || v < L) return INF;
    if (u <= L && v >= R) return tree[x];
    int mid = (L + R) >> 1;
    return min(Get(2*x, L, mid, u, v), Get(2*x+1, mid+1, R, u, v));
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("spoj.inp", "r", stdin);
        freopen("spoj.out", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> t[i] >> p[i];

    for (int i = 1; i <= 4*N; i++) tree[i] = INF;
    Build(1, 1, N);
    Update(t[1], p[1]);
    dp[1] = p[1];
    for (int i = 2; i <= N; i++)
        dp[i] = Get(1, 1, N, i-1, N) + p[i], Update(t[i], dp[i]);

    cout << Get(1, 1, N, N, N);
}
