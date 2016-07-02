#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1000001;
const int inf = 2000000000;

ll a[N], f[N], s[N], it[4*N];
int n, L, R;

void build(int x, int L, int R) {
    if (L == R) {
        it[x] = s[L];
    } else {
        int mid = (L + R) >> 1;
        build(2*x, L, mid);
        build(2*x+1, mid+1, R);
        it[x] = min(it[2*x], it[2*x+1]);
    }
}

ll get(int x, int L, int R, int u, int v) {
    if (L > v || R < u) return inf;
    if (L >= u && R <= v) return it[x];
    int mid = (L + R) >> 1;
    ll left = get(2*x, L, mid, u, v);
    ll right = get(2*x+1, mid+1, R, u, v);
    return min(left, right);
}

int main() {
    freopen("maxsubseq.inp", "r", stdin);
    freopen("maxsubseq.out", "w", stdout);
    //freopen("in.txt", "r", stdin);
    scanf("%d %d %d\n", &n, &L, &R);
    for (int i = 1; i <= n; i++) {
        scanf("%lld ", &a[i]);
        s[i] = a[i] + s[i-1];
    }
    build(1, 1, n);
    //for (int i = 1; i <= n; i++) cerr << s[i] << " ";
    //cerr < endl << get(1, 1, n, 5, 6) << endl;
    for (int i = R + 1; i <= n; i++)
        f[i] = s[i] - get(1, 1, n, i-R, i-L);
    //for (int i = 1; i <= n; i++) cerr << f[i] << " ";
    cout << *max_element(f + 1, f + n + 1);
}

