#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 100001;

int n, m;

vector<ii> tr;
ll a[N], b[N], d[N];

bool ok(ll x, int op) {
    memset(d, 0, sizeof d);
    int pos = 0;
    for (int i = 1; i <= n; i++) {
        d[i] = a[i];
        if (a[i] >= x) continue;
        int j;
        for (j = pos + 1; j <= m; j++)
            if (b[j] >= x - a[i]) break;
        d[i] += b[j];
        pos = j;
        if (op) tr.push_back(ii(i, pos));
    }
    for (int i = 1; i <= n; i++)
        if (d[i] < x) return false;
    return true;
}

bool cmp(ii a, ii b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

int main() {
    ios_base::sync_with_stdio(0);
    freopen("wall.inp", "r", stdin);
    freopen("wall.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> b[i];

    ll L = 0, R = (ll) 1e15;
    while (L < R - 1) {
        ll mid = L + (R - L)/2;
        if (ok(mid, 0)) L = mid;
        else R = mid;
    }

    cout << R - 1 << " ";
    ok(R - 1, 1);
    cout << tr.size() << endl;
    sort(tr.begin(), tr.end(), cmp);
    for (int i = 0; i < tr.size(); i++) cout << tr[i].x << " " << tr[i].y << endl;

    return 0;
}
