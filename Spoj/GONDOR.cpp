#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

#define x first
#define y second

using namespace std;

const int maxN = 128;
const int INF  = 0x3f3f3f3f;

typedef pair<double, double> pdd;
typedef pair<double, int> pdi;

priority_queue <pdd, vector<pdd>, greater<pdd> > Q;

int G[maxN][maxN];
double d[maxN];
pdd city[maxN];
int lmt[maxN], n;
bool f[maxN];

inline double dist(pdd &a, pdd &b) {
        return hypot(a.x - b.x, a.y - b.y);
}

void Dijkstra() {
        int u, v, i, cnt;
        double dd;
        Q.push(pdi(0.0, 1));    d[1] = 0.0;

        while (!Q.empty()) {
                u = Q.top().y;  Q.pop();
                if (f[u]) continue;
                cnt = lmt[u];
                for (int i = 0; i < n-1 && cnt; i++) {
                        v = G[u][i];
                        if (!f[v]) {
                                cnt--;
                                dd = dist(city[u], city[v]);
                                if (d[v] > d[u] + dd)
                                        d[v] = d[u] + dd,
                                        Q.push(pdi(d[v], v));
                        }
                }
                f[u] = true;
        }
}

int main() {
        //freopen("spoj.inp", "r", stdin);
        //freopen("spoj.out", "w", stdout);

        cin >> n;
        for (int i = 1; i <= n; i++) {
                double x, y;
                cin >> x >> y >> lmt[i];
                city[i] = pdd(x, y);
                for (int j = 0; j < n-1; j++) cin >> G[i][j];
                d[i] = 1e15;    f[i] = false;
        }

        Dijkstra();

        for (int i = 1; i <= n; i++) printf("%lf\n", d[i]);
        return 0;

        return 0;
}
