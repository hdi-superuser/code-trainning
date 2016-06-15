#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int N, M, source, target;
vector <int> a[12309];
int c[2309][2309], f[2309][2309], d[12309];

bool findpath(int start, int target) {
        queue <int> qu;
        for (int i = 1; i <= N; i++) d[i] = 0;
        d[start] = 1000111000;
        qu.push(start);

        while (qu.size()) {
                int u = qu.front();     qu.pop();
                if (u == target) return true;
                int i, v;
                for (i = 0; v = a[u][i]; i++)
                        if (d[v] == 0 && c[u][v] > f[u][v])
                                d[v] = u,
                                qu.push(v);
        }
        return false;
}

void enlarge() {
        int u, v, delta = 1000111000;
        for (v = target; (u = d[v]) != 1000111000; v = u)
                delta = min(delta, c[u][v] - f[u][v]);
        for (v = target; v != source; v = u)
                u = d[v],
                f[u][v] += delta,
                f[v][u] -= delta;
}

long long answer(int u) {
        int i, v;
        long long r = 0;
        for (i = 0; v = a[u][i]; i++) r += f[u][v];
        return r;
}

int main() {
        #ifndef ONLINE_JUDGE
                freopen("KARP.INP", "r", stdin);
                freopen("KARP.OUT", "w", stdout);
        #endif // ONLINE_JUDGE

        cin >> N >> M >> source >> target;
        for (int i = 1; i <= M; i++) {
                int p, q, w;
                cin >> p >> q >> w;
                a[p].push_back(q);
                a[q].push_back(p);
                c[p][q] = w;
        }

        for (int i = 1; i <= N; i++) a[i].push_back(0);

        while (findpath(source, target)) enlarge();

        cout << answer(source);

        return 0;
}

