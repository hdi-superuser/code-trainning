#include <bits/stdc++.h>

#define ALL(x) (x).begin(), (x).end()

using namespace std;

const int N = 100001;
typedef vector<int> vi;

int n, m, a[N];
vi it[4*N], temp;

void build(int x, int L, int R) {
    if (L == R) {
        it[x].push_back(a[L]);
        return;
    } else {
        int mid = (L + R) >> 1;
        build(2*x, L, mid);
        build(2*x+1, mid+1, R);
        it[x].resize(it[2*x].size() + it[2*x+1].size());
        merge(ALL(it[2*x]), ALL(it[2*x+1]), it[x].begin());
    }
}

int query(int x, int L, int R, int u, int v, int val) {
    if (L > v || R < u) return 0;
    if (L >= u && R <= v) return
        lower_bound(ALL(it[x]), val) - it[x].begin();
    int mid = (L + R) >> 1;
    int left = query(2*x, L, mid, u, v, val);
    int right = query(2*x+1, mid+1, R, u, v, val);
    return left + right;
}

int calc(int L, int R, int k) {
    int low = 1, high = n;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (query(1, 1, n, L, R, a[mid]) < k) low = mid + 1;
        else high = mid - 1;
    }
    return a[low-1];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    freopen("kthnum.inp", "r", stdin);
    freopen("kthnum.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    build(1, 1, n);
    sort(a + 1, a + n + 1);

    while (m--) {
        int u, v, k;
        cin >> u >> v >> k;
        cout << calc(u, v, k) << endl;
    }

    return 0;
}
