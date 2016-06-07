#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 10001;

struct police {
    int t, l, r, pos, cost;
} p[N];

struct comp {
    bool operator() (pair<int, int> x, pair<int, int> y) {
        return x.first > y.first;
    }
};
int n;

bool cmp(police x, police y) {
    return x.l < y.l;
}

bool check(int x) {
    for (int i = 1; i <= n; i++) {
        p[i].t = x / p[i].cost;
        p[i].l = p[i].pos - p[i].t;
        p[i].r = p[i].pos + p[i].t;
    }
    sort(p + 1, p + n + 1, cmp);
    priority_queue < pair<int, int>, vector < pair<int, int> >, comp > q;
    int j = 1, u = 0;
    for (int i = 1; i <= n; i++) {
        while (p[j].l <= i && j <= n) {
            q.push(make_pair(p[j].r, j));
            j++;
        }
        if (!q.empty()) u = q.top().second, q.pop();
        if (p[u].r < i) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    freopen("in.ads", "r",stdin);
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> p[i].pos >> p[i].cost;
    int L = 0, R = N*N, res;
    while (L <= R) {
        int mid = (L + R) >> 1;
        if (check(mid)) res = mid, R = mid - 1; else L = mid + 1;
    }

    cout << res;
    return 0;
}
