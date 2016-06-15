/*
    [VOI 2007] QBROBOT
    06-02-2016
    Dijkstra + Bianry search
*/

#include <iostream>
#include <cstdio>

#define task "QBROBOT"

using namespace std;

const int maxN = 501;
const int INF  = 1000000000;

int N, M, lim;
int isf[maxN], x[maxN], dist[maxN];
int C[maxN][maxN], P[maxN][maxN];

void Dijkstra() {
    fill(x, x + N, 1);
    fill(dist, dist + N, INF);

    dist[0] = 0;
    while (x[N-1]) {
        int u, dist_min = INF;

        for (int i = 0; i < N; i++)
            if (x[i] && dist[i] < dist_min) u = i, dist_min = dist[i];

        x[u] = 0;

        for (int v = 0; v < N; v++)
            if (x[v] && dist[v] > dist_min + C[u][v])
                dist[v] = dist_min + C[u][v];
    }
}

bool DFS(int u, int lastp) {
    if (lastp > lim) return false;
    if (u == N - 1) return true;
    if (isf[u]) lastp = 0;

    for (int v = 0; v < N; v++)
        if (dist[u] + C[u][v] == dist[v])
            if (DFS(v, lastp + P[u][v])) return true;

    return false;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(task".INP", "r", stdin);
        freopen(task".OUT", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> N;
    for (int i = 0; i < N; i++) cin >> isf[i];

    cin >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) C[i][j] = P[i][j] = INF;

    for (int i = 0; i < M; i++) {
        int u, v, t, f;

        cin >> u >> v >> t >> f;
        u--;    v--;
        C[u][v] = C[v][u] = t;
        P[u][v] = P[v][u] = f;
    }

    Dijkstra();

    int L = 1, R = INF;
    isf[0] = isf[N-1] = 1;

    while (L < R) {
        lim = (L + R) >> 1;

        if (DFS(0, 0)) R = lim;
        else L = lim + 1;
    }

    cout << L;

    return 0;
}
