#include <bits/stdc++.h>

#define task "main"

using namespace std;

typedef long long ll;

const int N = 5001;
const ll inf = 0x3f3f3f3f3f3f;

int n, s, e;
int next[N], a[N], b[N], c[N], d[N], x[N];

ll cost(int i, int j) {
    if (i > j) return 1LL*abs(x[i] - x[j]) + 1LL*c[i] + 1LL*b[j];
    else if (j > i) return 1LL*abs(x[i] - x[j]) + 1LL*d[i] + 1LL*a[j];
    return 0;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> s >> e;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> d[i];

    next[s] = e;
    ll ans = cost(s, e);

    for (int i = 1; i <= n; i++) {
        if (i == s || i == e) continue;
        int best_pos = s;
        ll change_value = inf;

        for (int j = s; j != e; j = next[j]) {
            ll temp = cost(j, i) + cost(i, next[j]) - cost(j, next[j]);
            if (temp < change_value) change_value = temp, best_pos = j;
        }

        next[i] = next[best_pos];
        next[best_pos] = i;
        ans += change_value;
    }

    cout << ans;

    return 0;
}
