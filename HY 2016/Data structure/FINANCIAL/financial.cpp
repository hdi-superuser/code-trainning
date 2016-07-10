#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

const int N = 100001;
const int inf = 2000000000;

typedef pair<int, int> ii;

int n, k;
int a[N], d[N], l[N], r[N], t[N];
ii it[4*N], f[N], lazy[4*N];

void compress() {
    sort(t + 1, t + n + 1);
    int m = unique(t + 1, t + n + 1) - t - 1;
    for (int i = 1; i <= n; i++) {
        d[i] = lower_bound(t + 1, t + m + 1, a[i]) - t;
        int temp = lower_bound(t + 1, t + m + 1, a[i] - k) - t;
        if (abs(a[i] - t[temp]) < k) temp--;    l[i] = temp;
        temp = lower_bound(t + 1, t + m + 1, a[i] + k) - t;
        if (abs(a[i] - t[temp]) < k) temp++;    r[i] = temp;
    }
}

void build(int node, int L, int R, int u, int v) {
    if (L == R) {
        it[node] = ii(0, L);
    } else {
        int mid = (L + R) >> 1;
        build(2*node, L, mid, u, v);
        build(2*node + 1, mid + 1, R, u, v);
        it[node] = max(it[2*node], it[2*node+1]);
    }
}

void lazy_update(int node) {
    if (lazy[node].x == 0) return;
    it[2*node] = lazy[node];
    it[2*node+1] = lazy[node];
    lazy[2*node] = lazy[node];
    lazy[2*node+1] = lazy[node];
    lazy[node] = ii(0, 0);
}

void update(int node, int L, int R, int pos, ii val) {
    if (L > pos || R < pos) return;
    if (L == pos && R == pos) {
        it[node] = val;
        lazy[node] = val;
        return;
    }
    lazy_update(node);
    int mid = (L + R) >> 1;
    update(2*node, L, mid, pos, val);
    update(2*node+1, mid+1, R, pos, val);
    it[node] = max(it[2*node], it[2*node+1]);
}

ii query(int node, int L, int R, int u, int v) {
    if (L > v || R < u) return ii(0, 0);
    if (L >= u && R <= v) return it[node];
    lazy_update(node);
    int mid = (L + R) >> 1;
    ii left = query(2*node, L, mid, u, v);
    ii right = query(2*node+1, mid+1, R, u, v);
    return max(left, right);
}

int main() {
    ios_base::sync_with_stdio(0);   cin.tie(NULL);
    freopen("financial.inp", "r", stdin);
    freopen("financial.out", "w", stdout);

    int MAX = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i], t[i] = a[i];

    compress();

    for (int i = 1; i <= n; i++) {
        f[i] = max(query(1, 1, n, 1, l[i]), query(1, 1, n, r[i], n));
        f[i].x++;
        if (f[i].x) update(1, 1, n, d[i], ii(f[i].x, i));
    }

    ii ans = ii(0, 0);  int pos;
    for (int i = 1; i <= n; i++)
        if (ans < f[i]) ans = f[i], pos = i;

    vector <int> res;   res.push_back(pos);
    while (f[ans.y].y) {
        res.push_back(ans.y);
        ans.y = f[ans.y].y;
    }

    if (ans.y) res.push_back(ans.y);
    sort(res.begin(), res.end());
    cout << ans.x << endl;
    for (int i = 0; i < res.size(); i++) cout << a[res[i]] << " ";

    return 0;
}
