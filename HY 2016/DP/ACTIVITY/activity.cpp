#include <bits/stdc++.h>

using namespace std;

const int N = 10001;

int n;
struct pack {
    int pos, s, f;
} a[N];
int f[N], pre[N];

bool cmp(pack a, pack b) {
    return a.s < b.s;
}

int main() {
    freopen("activity.inp", "r", stdin);
    freopen("activity.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].s >> a[i].f, a[i].pos = i;

    sort(a + 1, a + n + 1, cmp);
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[i].s >= a[j].f && f[i] < f[j] + 1)
                f[i] = f[j] + 1,
                pre[i] = j;
    }

    int ans = max_element(f + 1, f + n + 1) - f;
    cout << f[ans] << endl;
    vector <int> res;
    while (pre[ans]) {
        res.push_back(a[ans].pos);
        ans = pre[ans];
    }
    res.push_back(a[ans].pos);

    for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << endl;

    return 0;
}
