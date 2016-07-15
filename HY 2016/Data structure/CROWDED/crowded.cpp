#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

const int N = 1000001;

pair<int, int> a[N];

int n, d, cnt[N];

void Multiset() {
    int ans = 0;
    multiset<int> p, q;
    int j = 0, k = 0;
    for(int i = 0; i < n; i++) {
        while(k < n && a[k].x <= a[i].x + d) q.insert(a[k++].y);
        while(a[j].x + d < a[i].x) p.erase(p.find(a[j++].y));
        p.insert(a[i].y);
        if (*--p.end() >= 2 * a[i].y && *--q.end() >= 2 * a[i].y) ans++;
        q.erase(q.find(a[i].y));
    }
    cout << ans;
}

void Deque() {
    deque <int> q, p;
    for (int i = 0; i < n; i++) {
        while (!q.empty() && a[q.front()].x > a[i].x - d) q.pop_front();
        while (!q.empty() && a[q.back()].y < a[i].y) q.pop_back();
        q.push_back(i);
        cnt[i] += (a[q.front()].y >= 2*a[i].y);
    }

    for (int i = n - 1; i >= 0; i--) {
        while (!p.empty() && a[p.front()].x > a[i].x + d) p.pop_front();
        while (!p.empty() && a[p.back()].y < a[i].y) p.pop_back();
        p.push_back(i);
        cnt[i] += (a[p.front()].y >= 2*a[i].y);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) ans += (cnt[i] == 2 ? 1 : 0);
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("crowded.inp", "r", stdin);
    freopen("crowded.out", "w", stdout);

    cin >> n >> d;
    for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
    sort(a, a + n);

    Multiset();

    return 0;
}
