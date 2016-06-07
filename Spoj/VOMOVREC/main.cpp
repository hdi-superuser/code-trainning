#include <iostream>
#include <cstdio>

using namespace std;

const int N = 100001;
const int inf = int(1e9);

struct pol {
    long long x1, x2, y1, y2;
} p[N];
int n;

bool ok(long long k) {
    long long x = p[1].x1 - k, y = p[1].y1 - k;
    long long u = p[1].x2 + k, v = p[1].y2 + k;
    for (int i = 2; i <= n; i++)
        x = max(x, p[i].x1 - k),
        y = max(y, p[i].y1 - k),
        u = min(u, p[i].x2 + k),
        v = min(v, p[i].y2 + k);
    return x < u && y < v;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    freopen("in.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i].x1 >> p[i].y1 >> p[i].x2 >> p[i].y2;
    long long L = 0, R = 2*inf, res;
    while (L <= R) {
        long long mid = (L + R) >> 1;
        if (ok(mid)) res = mid, R = mid - 1; else L = mid + 1;
    }
    cout << res;
    return 0;
}
